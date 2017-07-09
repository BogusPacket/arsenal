#include <iostream>
#include <cstdlib>
#include <string>
#include <curl/multi.h>

#define ROOT_URL "https://www.g2a.com/marketplace/product/auctions/?id=94"
#define FILE_PATH "/root/arsenal/product_ids"
#define MAX 100

static void init(CURLM *cm, int i){
	CURL *eh = curl_easy_init();
	curl_easy_setopt(eh, CURLOPT_WRITEFUNCTION, cb);
	curl_easy_setopt(eh, CURLOPT_HEADER, 0L);
	curl_easy_setopt(eh, CURLOPT_URL, urls[i]);
	curl_easy_setopt(eh, CURLOPT_PRIVATE, urls[i]);
	curl_easy_setopt(eh, CURLOPT_VERBOSE, 0L);
	curl_multi_add_handle(cm, eh);}

void curl(){
	CURLM *cm;
	unsigned int c=0
	curl_global_init(CURL_GLOBAL_ALL);
	cm = curl_multi_init();
	curl_multi_setopt(cm, CURLMOPT_MAXCONNECTS, (long)MAX);
	for(c = 0; c < MAX; ++c){
	 init(cm, c)}
	
/*
	CURL *curl;
	CURLcode res;
	curl = curl_easy_init();
	if(curl){
	 curl_easy_setopt(curl, CURLOPT_URL, ROOT_URL)
	 res = curl_easy_perform(curl);
*/
	return;
}
