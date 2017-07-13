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
    MySQL(char*, int, char*, char*);
    MySQL(const char*, int, const char*, const char* const char*);
    MySQL(char const*, int, char const*, char const*, char const*);
    MySQL(std::string&, int, std::string&, std::string&, std::string&);
};
#endif
