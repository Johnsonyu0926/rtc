#pragma once

#include "json.hpp"
#include "audiocfg.hpp"

namespace asns {

class TestFile {
public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE_WITH_DEFAULT(TestFile, ffmpegCmd)

    std::string ffmpegCmd = "ffplay -fflags nobuffer -nodisp -analyzeduration 1 %s &";
};

class TestFileBusiness {
public:
    static const std::string TEST_FILE;

    TestFileBusiness() {
        CAudioCfgBusiness business;
        business.load();
        filePath = business.business[0].savePrefix + TEST_FILE;
        load();
    }

    void load() {
        std::ifstream ifs(filePath);
        if (!ifs.is_open()) {
            LOG(INFO) << "open test.json fail";
            return;
        }

        try {
            json js;
            ifs >> js;
            testFile = js.get<TestFile>();
        } catch (const json::parse_error &ex) {
            LOG(ERROR) << "parse error at byte " << ex.byte;
        }

        ifs.close();
    }

    std::string getFfmpegCmd() const {
        return testFile.ffmpegCmd;
    }

private:
    TestFile testFile;
    std::string filePath;
};

const std::string TestFileBusiness::TEST_FILE = "/cfg/test.json";

} // namespace asns
