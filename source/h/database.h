#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <memory>
#include <vector>

class CDatabase {
public:
    CDatabase();
    virtual ~CDatabase();

    bool Connect(const std::string& connectionString);
    void Disconnect();
    bool ExecuteQuery(const std::string& query);
    std::vector<std::string> FetchResults();

private:
    class Impl;
    std::unique_ptr<Impl> pImpl;
};

#endif // DATABASE_H
