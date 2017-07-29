#ifndef SOCKET_H
#define SOCKET_H
#include "arsenal.h"
class TCP;

template<class P> class Socket : protected Arsenal {
  protected:
    int sock;
    char datagram[4096];
    struct sockaddr_in server;
  public:
      void dport(int port){server.sin_port=htons(port);}
      int CONNECT(){return connect(sock , (struct sockaddr *)&server , sizeof(server));};
      template <class Dst> void dst(Dst d){server.sin_addr.s_addr=inet_addr(dst);}
      Socket<P>(){;}
};

class TCP : public Socket<TCP> {
  public:
  TCP(){this->sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        this->server.sin_family=AF_INET;}};

#endif
