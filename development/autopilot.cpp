#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#define POPULAR_ITEMS "https://www.g2a.com/lucene/search/filter?jsoncallback=jQuery111007667557919303079_1500323788288&skip=&minPrice=0.00&maxPrice=900.00&cc=US&stock=all&event=bestseller&platform=0&search=&genre=0&cat=0&sortOrder=popularity+desc&start=0&rows=12&steam_app_id=&steam_category=&steam_prod_type=&includeOutOfStock=&includeFreeGames=false&isWholesale=false&_=1500323788290"
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
    char url[] = POPULAR_ITEMS;
    curl_easy_setopt(curl, CURLOPT_URL, url);
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
