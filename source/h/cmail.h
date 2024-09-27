#ifndef CMAIL_H
#define CMAIL_H

#include <string>
#include <vector>
#include <memory>

class CMail {
public:
    CMail();
    virtual ~CMail();

    bool Init(const std::string& mailServer);
    bool SendMail(const std::string& recipient, const std::string& subject, const std::string& body);
    bool ReceiveMail(std::vector<std::string>& emails);

private:
    std::string m_mailServer;
    int m_port;
};

#endif // CMAIL_H
