#include "arsenal.h"
#include "mysql.h"

using namespace std;
int main(int argc, char* argv[]){
  string host = "127.0.0.1";
  string user = "root";
  string pass = "choppersrus";
  MySQL<TCP> m(host, user, pass);
  m.setPort(3306);
  m.switchDatabase("autopilot");
  q = m.query();
  q.execute("SELECT * FROM ITEMS")
  return 1;
}
