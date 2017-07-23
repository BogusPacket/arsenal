#include "arsenal.h"
#include "g2a.h"

G2A::G2A(){;}
G2A::~G2A(){;}

struct Item {
	int id;
	std::string name;
};

inline void print_item_vector(std::vector<struct Item>& v){
for(std::vector<int>::size_type i = 0; i != v.size(); i++) {
std::cout << COLOR_RED << "+" << COLOR_RESET << std::endl;
std::cout << COLOR_RED << "| "  << COLOR_MAGENTA << "PRODUCTID" << COLOR_YELLOW << ">\t" << COLOR_RESET << v[i].id << std::endl;
std::cout << COLOR_RED << "| " << COLOR_MAGENTA << "NAME" << COLOR_YELLOW << ">\t\t" << COLOR_RESET << "\"" << v[i].name << "\"" << std::endl;
std::cout << COLOR_RED << "+" << COLOR_RESET << std::endl;}}

std::vector<struct Item> item_regex(std::string& js){
		std::vector<struct Item> v;
		std::string buf = js;
		std::regex re("(?:\"id\":)([0-9]+)(?:,\"name\":\")([^\"]+)");
                std::smatch m;
                int i = 1;
                while (std::regex_search(buf, m, re))
                {
			Item item;
			std::string::size_type sz;
			item.id = std::stoi(m[1], &sz);
			item.name = m[2];
			v.push_back(item);
			buf = m.suffix();
        	};
		return v;
}

size_t curl_callback(void *contents, size_t size, size_t nmemb, void *userp){
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;}

void CURL_PREP(CURL* curl, std::string& buf){
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curl_callback);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buf);
	#ifdef SKIP_PEER_VERIFICATION
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        #endif
        #ifdef SKIP_HOSTNAME_VERIFICATION
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        #endif
	return;}

void G2A::updateITEMS(int num){
	curl_global_init(CURL_GLOBAL_DEFAULT);
	if (num <= 24) {
	while (1){
		CURL* curl = curl_easy_init();
		CURLcode res;
		std::string buf;
		curl = curl_easy_init();
		std::string url = POPULAR_ITEMS;
		url.append("0&rows=");
    		url.append(std::to_string(num));
    		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		CURL_PREP(curl, buf);
    		res = curl_easy_perform(curl);
    		if(res != CURLE_OK){std::cout << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;}
  		int i = 1;
		std::vector<struct Item> v;
		//item_regex(buf, v);
    		curl_easy_cleanup(curl);
		curl_global_cleanup();
	}	} else {
        int i = 0;
	Arsenal::Set<std::vector<struct Item>> s
        while (i < num){
		CURL* curl = curl_easy_init();
		CURLcode res;
		std::string buf;
                std::string url;
                if ((num - i) < 24){
                        url = POPULAR_ITEMS;
                        url += std::to_string(i);
                        url += "&rows=";
                        url += std::to_string(num - i);
                        i += (num - i);} else {
                                url = POPULAR_ITEMS;
                                url += std::to_string(i);
                                url += "&rows=24";
                                i += 24;}
                curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		CURL_PREP(curl, buf);
        	res = curl_easy_perform(curl);
		if(res != CURLE_OK){std::cout << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;}
		s.cat(item_regex(buf));
		curl_easy_cleanup(curl);
	}
	curl_global_cleanup();
   }
}

