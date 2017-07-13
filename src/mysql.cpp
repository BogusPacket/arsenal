#include "arsenal.h"
#include "mysql.h"

class MySQL {
  private: 
    sql::Driver* driver;
    sql::Connection* connection
  public:
    MySQL(const char* host, int port, char* user, char* pass){
    }
    
};
#endif
