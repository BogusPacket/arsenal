#ifndef SOCKET_H
#define SOCKET_H
#include "arsenal.h"
#define TCP 0x01
#define UDP 0x02


template<char const P> class Socket : protected Arsenal {
  private:
  int sock;
  char datagram[4096];
  struct sockaddr_in server;
  public:
    template<class Dst> Socket(Dst dst, int port);
    template<class Buf> recieve(Buf* buf, size_t max);
   
};

template<> template<class Dst> class Socket<TCP>::Socket(Dst dst, int port){
      sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
      server.sin_addr.s_addr=inet_addr(dst);
      server.sin_port=htons(port);
      server.sin_family=AF_INET;
      connect(sock , (struct sockaddr *)&server , sizeof(server));}

template<typename P> void Socket<P>::setPort(int port){server.sin_port=htons(port);}
template<typename P> template<class Dst> void Socket<P>::setDst(Dst dst){server.sin_addr.s_addr=inet_addr(dst);}
template<typename P> template<class Buf> int Socket<P>::recieve(Buf* buf, size_t max){
      int bytesRecieved = 0, totalBytesRecieved = 0;
      while (!((bytesRecieved=recv(sock, buf, 65535, MSG_DONTWAIT))<=0)){totalBytesRecieved += bytesRecieved;}}

#endif
