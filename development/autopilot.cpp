#include <iostream>
#include <string>
#include <curl/curl.h>

class Autopilot{
private:
  Curl* curl;
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
      std::string url = "https://www.g2a.com/marketplace/product/auctions/?id=";
      url += std::to_string(i);
      curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
     #ifdef SKIP_PEER_VERIFICATION
      curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
      #endif
      #ifdef SKIP_HOSTNAME_VERIFICATION
      curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
      #endif
      res = curl_easy_perform(curl);
      if(res != CURLE_OK){
        std::cout << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        curl_easy_cleanup(curl);
      }
      std::cout << res << std::endl;
      i++;
    }
    curl_global_cleanup();
    
  }
  ~Autopilot(){;}
};

int main()
