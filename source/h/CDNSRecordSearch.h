#ifndef CDNSRECORDSEARCH_H
#define CDNSRECORDSEARCH_H

#include <string>
#include <vector>
#include <atomic>
#include "check.h"
#include "database.h"
#include "global.h"
#include "log.h"
#include "netfilter.h"

class CDNSRecordSearch {
public:
    CDNSRecordSearch();
    virtual ~CDNSRecordSearch();

    bool Start();
    void Stop();
    bool AddDNSRecord(const std::string& domain, const std::string& ip);

private:
    bool SearchDNSRecord(const std::string& domain, std::string& ip);

    std::vector<std::pair<std::string, std::string>> m_DNSRecords;
    std::atomic<bool> m_bRunning;
};

#endif // CDNSRECORDSEARCH_H
