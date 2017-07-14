#include "arsenal.h"
#include "mysql.h"

using namespace std;
int main(int argc, char* argv[]){
  string host = "104.36.18.243";
  string user = "root";
  string pass = "choppersrus";
  MySQL<TCP> m(host, user, pass);
  m.setPort(3306);
  m.switchDatabase("autopilot");
  m.execute("SELECT * FROM ITEMS");
  return 1;
}
