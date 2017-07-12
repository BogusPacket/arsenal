#ifndef MYSQL_H
#define MYSQL_H
#include "arsenal.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
class MySQL{
  private:
    sql::Driver*;
    sql::Connection*;
  public:
    MySQL(const char*, int, const char*, const char*);
}
#endif
