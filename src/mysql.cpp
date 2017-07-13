#include "arsenal.h"
#include "mysql.h"

class MySQL {
  private: 
    sql::Driver* driver;
    sql::Connection* connection
  public:
    MySQL(char* host, int port, char* user, char* pass){}
    MySQL(const char* host, int port, const char* user, const char* pass){}
};
