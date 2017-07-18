#include <iostream>
#include <string>
#include <regex>
#include <curl/curl.h>
#define POPULAR_ITEMS "https://www.g2a.com/lucene/search/filter?jsoncallback=jQuery111007667557919303079_1500323788288&skip=&minPrice=0.00&maxPrice=900.00&cc=US&stock=all&event=bestseller&platform=0&search=&genre=0&cat=0&sortOrder=popularity+desc&steam_app_id=&steam_category=&steam_prod_type=&includeOutOfStock=&includeFreeGames=false&isWholesale=false&_=1500323788290&start="
#define G2A_BESTSELLERS 0x01
#define DYN "&start=0&rows=12"

static inline void CURL_PREP(CURL* curl){
    #ifdef SKIP_PEER_VERIFICATION
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
    #endif
    #ifdef SKIP_HOSTNAME_VERIFICATION
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
    #endif
    return;
}
static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}


void updateITEMS(int num){
  std::string buf;
  int remainder = 0;
  if (!(num <= 24)){
    remainder = num % 24;
  }
  CURLM *multicurl;
  curl_global_init(CURL_GLOBAL_DEFAULT);
  if (remainder == 0) {
    std::cout << "Remainder = 0" << std::endl;
    CURL* curl;
    CURLcode res;
    curl = curl_easy_init();
    std::string url = POPULAR_ITEMS;
    url.append("&start=0&rows=");
    url.append(std::to_string(num));
    std::cout << url.c_str() << std::endl; 
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buf);
    CURL_PREP(curl);
    res = curl_easy_perform(curl);
    if(res != CURLE_OK){
        std::cout << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
    }
    curl_easy_cleanup(curl);
    } else {
        CURLM *multicurl;
        int i = num;
        while (num){
            CURL* curl =  curl_easy_init();
            std::string url;
            if (i < 24){
                url = POPULAR_ITEMS;
                url += std::to_string(num - i);
                url += "&rows=";
                url += std::to_string(i);
                i = 0;
            } else {
                url = POPULAR_ITEMS;
                url += std::to_string(num - i);
                url += "&rows=24";
                i += 24;
        }
        std::cout << url << std::endl;
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buf);
        CURL_PREP(curl);
        curl_multi_add_handle(multicurl, curl);
        }
        int U;
        curl_multi_perform(multicurl, &U);
        curl_multi_cleanup(multicurl);
    }
  curl_global_cleanup();
  std::regex r("(?:\"id\":)(\\d+)");
  std::smatch m;
  for(auto it = std::sregex_iterator(buf.begin(), buf.end(), r);
    it != std::sregex_iterator();
     ++it)
    {
    std::cout << "New Product ID:\t" << (*it)[1] << std::endl;
  }
}
int main(int argc, char* argv[]){
  updateITEMS(24);
  return 1;
}
