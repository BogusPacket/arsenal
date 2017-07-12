#include "mysql.h"

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
