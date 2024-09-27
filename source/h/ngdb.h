#ifndef NGDB_H
#define NGDB_H

#include <string>
#include <vector>
#include <memory>

class CNGDB {
public:
    CNGDB();
    virtual ~CNGDB();

    bool Connect(const std::string& connectionString);
    void Disconnect();
    bool ExecuteQuery(const std::string& query);
    std::vector<std::string> FetchResults();

private:
    class Impl;
    std::unique_ptr<Impl> pImpl;
};

#endif // NGDB_H
