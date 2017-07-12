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
  template <typename H, typename U, typename P, typename D>
  MySQL(H host, int port, U user, P pass, D dev){
    std::stringstream s;
    s << host;
    s << ":";
    s << port;
    std::cout << s;
  }
  
};
#endif
