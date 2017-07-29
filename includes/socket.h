#ifndef SOCKET_H
#define SOCKET_H
#include "arsenal.h"

class TCP;
class UDP;

template<class P> class Socket : protected Arsenal {
  private:
    int sock;
    char datagram[4096];
    struct sockaddr_in server;
  public:
      void setPort(int port){server.sin_port=htons(port);}
      Socket(){;}
      template<class Dst> setDst(Dst dst){server.sin_addr.s_addr=inet_addr(dst);}
      template<class Buf> recieve(Buf* buf, size_t max){
        int bytesRecieved = 0, totalBytesRecieved = 0;
        while (!((bytesRecieved=recv(sock, buf, 65535, MSG_DONTWAIT))<=0)){totalBytesRecieved += bytesRecieved;}}   */
};

template<> class TCP : public Socket<TCP> {
  TCP(){this->sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        this->server.sin_family=AF_INET;};
};
#endif
