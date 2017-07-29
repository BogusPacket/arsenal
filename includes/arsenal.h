#ifndef ARSENAL_H
#define ARSENAL_H
#define COLOR_RED "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_YELLOW "\x1b[33m"
#define COLOR_BLUE "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN "\x1b[36m"
#define COLOR_RESET "\x1b[0m"
#define INFO_B "\x1b[0m[\x1b[34m+\x1b[0m] "
#define SUCCESS_B "\x1b[0m[\x1b[32m+\x1b[0m] "
#define ERROR_B "\x1b[0m[\x1b[31m+\x1b[0m] "
#define ARSENAL_G2A 0x01
#define ARSENAL_SOCKET 0x02
#include <bitset>
#include <iostream>
#include <string>
#include <regex>
#include <iomanip>
#include <cstdlib>
#include<sys/socket.h>
#include<netinet/tcp.h>   
#include<netinet/ip.h>
#include <arpa/inet.h>
#include <errno.h>
#include <vector>
#include <iterator>
#include <curl/curl.h>

class Arsenal {
  protected:
    int id;
    template<typename S> void print(S s);
    template<typename X> void err(X x);
    template<typename I> void info(I i);
    template<typename S> void success(S s);};
template<> void print(I i){std::cout << i << std::endl;}
template<> void err(X x){std::cout << ERROR_B << s << std::endl;}
template<> void info(I i){std::cout << INFO_B << s << std::endl;}
template<> void success(S s){std::cout << SUCCESS_B << s << std::endl;}
using namespace std;
  template <typename A> class Set : protected Arsenal {
  private:
    int checkVector(A& a){
      for(int x=0;x<v.size();++x){
      int r=memcmp(&a,&v[x],sizeof(A));
      if (r == 0){return 0;}}v.push_back(a);return 1;}
  public:
    vector<A> v;
    Set(){;}
    Set(A& a){v.push_back(a);}
    A operator[](int i){return v[i];}
    int push(A& a){if(checkVector(a) != 1){return 0;}else{return 1;}}
    void cat(vector<A> a){for(int i=0; i < a.size(); ++i){checkVector(a[i]);}}
  };

#endif
