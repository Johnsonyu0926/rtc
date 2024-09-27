#ifndef SCSI_H
#define SCSI_H

#include <string>
#include <vector>
#include <memory>

class CSCSI {
public:
    CSCSI();
    virtual ~CSCSI();

    bool Init(const std::string& device);
    bool Read(std::vector<uint8_t>& data, uint64_t address, size_t size);
    bool Write(const std::vector<uint8_t>& data, uint64_t address, size_t size);
    bool Format();

private:
    std::string m_device;
    int m_handle;
};

#endif // SCSI_H
