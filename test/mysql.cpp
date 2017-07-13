#include "arsenal.h"
#include "mysql.h"

using namespace std;
int main(int argc, char* argv[]){
  string host = "127.0.0.1";
  string user = "root";
  string pass = "choppersrus";
  MySQL m(host, user, pass, 3306, MYSQL_PROTO_TCP);
  return 1;
}
