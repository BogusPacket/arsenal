#ifndef MYSQL_H
#define MYSQL_H
#include "arsenal.h"
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
class MySQL{
  sql::Driver* driver;
  sql::Connection* connection;
  public:
    template<typename S>
    MySQL(S, int, S, S);
};
#endif
