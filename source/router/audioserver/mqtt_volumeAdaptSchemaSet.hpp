#pragma once

#include "Rs485NoiseMange.hpp"
#include "rs485Manage.hpp"

namespace asns {
    template<typename Quest, typename Result>
    class CReQuest;

    template<typename T>
    class CResult;

    class CVolumeAdaptSchemaSet {
    public:
        NLOHMANN_DEFINE_TYPE_INTRUSIVE_WITH_DEFAULT(CVolumeAdaptSchemaSet, null)

        template<typename Quest, typename Result, typename T>
        int do_success(const CReQuest<Quest, Result> &c, CResult<T> &r) {
            if (c.data.monitorStatus && !AcquisitionNoise::getInstance().getMonitorStatus()) {
                LOG(INFO) << "open rs485 noise";
                AcquisitionNoise::getInstance().setMonitorStatus(c.data.monitorStatus);
                Rs485::uart_fcntl_set(FNDELAY);
                CUtils::async_wait(1, 0, 0, [&] {
                    while (Rs485::get_rs485_state()) {
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                    }
                    Rs485NoiseMange::startCollectingNoise();
                    LOG(INFO) << "noise worker end";
                });
            } else if (!c.data.monitorStatus && AcquisitionNoise::getInstance().getMonitorStatus()) {
                LOG(INFO) << "open rs485 business";
                AcquisitionNoise::getInstance().setMonitorStatus(c.data.monitorStatus);
                AcquisitionNoise::getInstance().setDecibel(0);
                Rs485::uart_fcntl_set(FNDELAY);
                CUtils::async_wait(1, 0, 0, [&] {
                    while (Rs485::get_rs485_state()) {
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                    }
                    RSBusinessManage rs;
                    rs.worker();
                    LOG(INFO) << "business worker end";
                });
            }
            c.data.set_data();
            r.resultId = 1;
            r.result = "success";
            return 1;
        }

    private:
        std::nullptr_t null;
    };
}
