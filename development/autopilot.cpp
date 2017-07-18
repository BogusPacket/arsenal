#include <iostream>
#include <string>
#include <regex>
#include <curl/curl.h>
#define POPULAR_ITEMS "https://www.g2a.com/lucene/search/filter?jsoncallback=jQuery111007667557919303079_1500323788288&skip=&minPrice=0.00&maxPrice=900.00&cc=US&stock=all&event=bestseller&platform=0&search=&genre=0&cat=0&sortOrder=popularity+desc&start=0&rows=12&steam_app_id=&steam_category=&steam_prod_type=&includeOutOfStock=&includeFreeGames=false&isWholesale=false&_=1500323788290"

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

void updateITEMS(){
  CURL* curl;
  CURLcode res;
  curl_global_init(CURL_GLOBAL_DEFAULT);
  curl = curl_easy_init();
  std::string buf;
  char url[] = POPULAR_ITEMS;
  curl_easy_setopt(curl, CURLOPT_URL, url);
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buf);
  #ifdef SKIP_PEER_VERIFICATION
  curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
  #endif
  #ifdef SKIP_HOSTNAME_VERIFICATION
  curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
  #endif
  res = curl_easy_perform(curl);
  if(res != CURLE_OK){
    std::cout << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
  }
  curl_easy_cleanup(curl);
  curl_global_cleanup();
  std::regex r("\"id\":\\d+");
  std::smatch m;
  std::regex_search (buf,m,r);
  std::cout << m[1];
  std::cout << m[2];
  std::cout << m[3];
}
int main(void){
  updateITEMS();
  return 1;
}
