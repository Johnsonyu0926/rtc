#ifndef MIME_H
#define MIME_H

#include <string>
#include <vector>

class CMime {
public:
    CMime();
    virtual ~CMime();

    bool Init(const std::string& mimeContent);
    bool Parse(std::vector<std::string>& parts);
    std::string GetHeader(const std::string& headerName) const;
    std::string GetBody() const;

private:
    bool ParseHeaders();
    bool ParseBody();

    std::string m_mimeContent;
    std::vector<std::string> m_headers;
    std::string m_body;
};

#endif // MIME_H
