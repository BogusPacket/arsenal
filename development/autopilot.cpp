#include "arsenal.h"
#include "mysql.h"

class Autopilot{
private:
  sql::Connection* connection;
  sql::Driver* driver;
  Curl* curl;
  CURLcode res;
public:
  Autopilot(){
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
  }
  void updateITEMS(){
    #ifdef SKIP_PEER_VERIFICATION
    curl_easy_setopt(curl, CURLOPT_URL, "https://www.g2a.com/");
  }
  ~Autopilot(){;}
};
