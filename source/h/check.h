#ifndef CHECK_H
#define CHECK_H

#include <string>
#include "doorsbase.h"

extern bool _Check(const std::string& szAuthHost, int nAuthPort, const std::string& szCheckIp, const std::string& szUser, int nSize);

#endif // CHECK_H
