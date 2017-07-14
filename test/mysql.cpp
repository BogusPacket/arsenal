#include "arsenal.h"
#include "mysql.h"

using namespace std;
int main(int argc, char* argv[]){
  string host = "127.0.0.1";
  string user = "root";
  string pass = "choppersrus";
  MySQL<TCP> m(host, user, pass, 22);
  m.switchDatabase("autopilot");
  string s = "SELECT * FROM ITEMS";
  m.execute(s);
  return 1;
}
