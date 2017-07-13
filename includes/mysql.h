#ifndef MYSQL_H
#define MYSQL_H
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#define 
template<typename H, typename U, typename P>
class MySQL {
  private:
    sql::Driver *driver = NULL;
    sql::Connection *connection = NULL;
    
  public:
    MySQL(H host, U user, P passwd, int){
      
    }
};
#endif
