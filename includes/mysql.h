#ifndef MYSQL_H
#define MYSQL_H
#include "arsenal.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
class MySQL{
  public:
    MySQL(const char*, int, const char*, const char*);
};
#endif
