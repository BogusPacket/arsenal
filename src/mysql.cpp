#include "mysql.h"

class MySQL {
private:
  sql::Driver *driver = NULL;
  sql::Connection *connection = NULL;
public:
  MySQL(const char* host, int port, const char* user, const char* pass, char* dev){
    std::stringstream s;
    s << host;
    s << ":";
    s << port
    cout << s;
    connection = driver->connect(s.c_str(), user, pass);
  }
  
};
