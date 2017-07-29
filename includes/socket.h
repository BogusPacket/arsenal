#ifndef SOCKET_H
#define SOCKET_H
#include "arsenal.h"

template class TCP;
template class UDP;

template<class P> class Socket : protected Arsenal {
  private:
    int sock;
    char datagram[4096];
    struct sockaddr_in server;
  public:
      void setPort(int port){server.sin_port=htons(port);}
      Socket(){;}
};

template<> class TCP : public Socket<TCP> {
  TCP(){this->sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        this->server.sin_family=AF_INET;};
};
#endif
