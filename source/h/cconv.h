#ifndef CCONV_H
#define CCONV_H

#include <string>
#include "doorsbase.h"

constexpr size_t BUFLEN = 2000;

class CConv {
public:
    bool Utf8Encoding(const std::string& szSrc, std::string& szDest);

private:
    bool outbin(const std::string& outbin, std::string& szDest);
};

#endif // CCONV_H
