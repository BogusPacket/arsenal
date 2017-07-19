#include "arsenal.h"
#include "autopilot.h"
#include <iterator>
Autopilot::Autopilot(){;}
Autopilot::~Autopilot(){;}


size_t curl_callback(void *contents, size_t size, size_t nmemb, void *userp)
	{
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}
inline void CURL_SSL_PREP(CURL* curl){
	#ifdef SKIP_PEER_VERIFICATION
	curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        #endif
        #ifdef SKIP_HOSTNAME_VERIFICATION
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        #endif
}

inline void CURL_PREP(CURL* curl, std::string buf){
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curl_callback);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buf);
	CURL_SSL_PREP(curl);
}

void Autopilot::updateITEMS(int num){
	curl_global_init(CURL_GLOBAL_DEFAULT);
	CURL* curl = curl_easy_init();
	if (num <= 24) {
		CURLcode res;
		std::string buf;
		CURL_PREP(curl, buf);
		curl = curl_easy_init();
		std::string url = POPULAR_ITEMS;
		url.append("0&rows=");
    		url.append(std::to_string(num));
    		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    		res = curl_easy_perform(curl);
    		if(res != CURLE_OK){
        		std::cout << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
    		}
		std::regex re("(\\d)+");
  		std::smatch m;
  		int i = 1;
		std::regex_iterator<std::string::iterator> iter( buf.begin(), buf.end(), re);
		std::regex_iterator<std::string::iterator> rend;
  		while(iter != rend)
    		{
				for (int x = 0; x < iter->size(); x++){
    					std::cout << SUCCESS_B << "Product ID " << std::to_string(i) << ":\t" << COLOR_YELLOW << iter->str() << COLOR_RESET << std::endl;
				}
  			++iter;
  		}

    		curl_easy_cleanup(curl);
    } else {
        int i = 0;
        while (i < num){
		std::string buf;
                std::string url;
                if ((num - i) < 24){
                        url = POPULAR_ITEMS;
                        url += std::to_string(i);
                        url += "&rows=";
                        url += std::to_string(num - i);
                        i += (num - i);}
                                else {
                                url = POPULAR_ITEMS;
                                url += std::to_string(i);
                                url += "&rows=24";
                                std::cout << INFO_B << COLOR_MAGENTA << url << COLOR_RESET << std::endl;
                                i += 24;}
		CURL_PREP(curl, buf);
                curl_easy_setopt(curl, CURLOPT_URL, url);
        	curl_easy_perform(curl);
	}
        curl_easy_cleanup(curl);
   }
  curl_global_cleanup();
}

