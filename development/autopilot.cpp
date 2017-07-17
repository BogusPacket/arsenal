#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

class Autopilot{
private:
  CURL* curl;
  CURLcode res;
public:
  Autopilot(){
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    return;
  }
  void updateITEMS(){
    int i = 0;
    while (i < 10000) {
      char url[100] = "https://www.g2a.com/marketplace/product/auctions/?id=" + ;
      strcat(&url[strlen(url) + 1], std::to_string(i);
      curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
     #ifdef SKIP_PEER_VERIFICATION
      curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
      #endif
      #ifdef SKIP_HOSTNAME_VERIFICATION
      curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
      #endif
      res = curl_easy_perform(curl);
      if(res != CURLE_OK){
        printf("curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        curl_easy_cleanup(curl);
      }
        printf("curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
      i++;
    }
    curl_global_cleanup();
  }
  ~Autopilot(){;}
};

int main(void){
  Autopilot a;
  a.updateITEMS();
  return 1;
}
