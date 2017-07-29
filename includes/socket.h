#ifndef SOCKET_H
#define SOCKET_H
#include "arsenal.h"
#define tcp 0x01
class TCP;

template<char const P> class Socket : protected Arsenal {
  protected:
    int sock;
    char datagram[4096];
    struct sockaddr_in server;
  public:
      void setPort(int port){server.sin_port=htons(port);}
      Socket(){;}
};

class TCP : public Socket<tcp> {
  TCP(){this->sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        this->server.sin_family=AF_INET;};
};
#endif
