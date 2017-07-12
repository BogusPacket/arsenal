#ifndef MYSQL_H
#define MYSQL_H
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
class MySQL {
private:
  sql::Driver *driver = NULL;
  sql::Connection *connection = NULL;
public:
  template <typename S>
  MySQL(S host, int port, S user, S pass, S dev){
    std::stringstream s;
    s << host;
    s << ":";
    s << port
    cout << s;
  }
  
};
#endif
