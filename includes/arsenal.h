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
#include <bitset>
#include <iostream>
#include <string>
#include <regex>
#include <iomanip>
#include <cstdlib>
#include <errno.h>
#include <vector>
#include <iterator>
#include <curl/curl.h>
using namespace std;
namespace Arsenal {
  template <typename Arsenal> class Set;
  template <typename A> class Set<vector<A>> {
  private:
    vector<A> v;
    int checkVector(A a){
      for(int x=0;x<v.size();++x){
      int r=memcmp(&a,&v[x],sizeof(A));
      if (r<0 || r>0){return 0;}}v.push_back(a);return 1;}
  public:
    Set(){;}
    Set(vector<A> vec){;}
    A operator[](int i){return v[i];}
    int push(A a){if(checkVector(a) != 1){return 0;}else{return 1;}}
    void cat(vector<A> a){for(int i=0; i < a.size(); ++i){checkVector(a[i]);}}
  };
};

#endif
