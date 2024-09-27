#ifndef CQSEARCH_H
#define CQSEARCH_H

#include <string>

class CCQSearch {
public:
    CCQSearch();
    virtual ~CCQSearch() = default;

    bool Init();
    bool Search(const std::string& szQuery);

private:
    void ParseQuery(const std::string& szQuery);
    void ExecuteSearch();

    std::string m_szQuery;
};

#endif // CQSEARCH_H
