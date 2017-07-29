#ifndef SOCKET_H
#define SOCKET_H
#include "arsenal.h"
class TCP;
class UDP;

template<class P> class Socket : protected Arsenal {
  protected:
    int sock;
    char datagram[4096];
    struct sockaddr_in server;
    struct sockaddr_in b;
  public:
      void dport(int port){server.sin_port=htons(port);}
      int CONNECT(){return connect(sock , (struct sockaddr *)&server , sizeof(server));};
      template <class Dst> void dst(Dst d){server.sin_addr.s_addr=inet_addr(dst);}
      template <class Src> int LISTEN(Src s){return bind(sock, (sockaddr*)&b, sizeof(b));;}
      template <class Src> int LISTEN(Src s, int port){b.sin_port=htons(port);}
      template<class Msg> SEND(Msg m, int length){return sendto(this->sock, (const char*) m, length, 0, (sockaddr*)&this->server, sizeof(this->server));}
      Socket<P>(){b = {};}
};

class UDP : public Socket<UDP> {
public:
  UDP(){server.sin_family=AF_INET;
        this->sock = socket(AF_INET, SOCK_DGRAM, 0);}
 
};

class TCP : public Socket<TCP> {
  public:
  TCP(){this->sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        this->server.sin_family=AF_INET;}};

#endif
