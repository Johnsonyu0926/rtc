#ifndef CQSEARCH_H
#define CQSEARCH_H

#include <string>

class CCQSearch {
public:
    CCQSearch();
    virtual ~CCQSearch() = default;

    bool Init();
    bool Search(const std::string& query);

private:
    void ParseQuery(const std::string& query);
    void ExecuteSearch();

    std::string m_query;
};

#endif // CQSEARCH_H
