#include "arsenal.h"
#include "mysql.h"

using namespace std;
int main(int argc, char* argv[]){
  string host = "127.0.0.1";
  string user = "root";
  string pass = "choppersrus";
  MySQL<string> m(host, user, pass);
  return 1;
}
