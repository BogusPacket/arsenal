#ifndef SOCKET_H
#define SOCKET_H
#include<sys/socket.h>
#include<netinet/tcp.h>   
#include<netinet/ip.h>
#include <arpa/inet.h>
#define TCP 0x01

template<char const P> class Socket;
template<>
class Socket<TCP> {
  private:
    int fd;
    char datagram[4096];
    struct sockaddr_in server;
public:
    template <class D> Socket(D dst, int port){
      fd = socket (AF_INET, SOCK_STREAM, IPPROTO_TCP);
      server.sin_addr.s_addr=inet_addr(dst);
      server.sin_family=AF_INET;
      server.sin_port=htons(port);
      connect(fd , (struct sockaddr *)&server , sizeof(server));
    }
    void setPort(int port){server.sin_port=htons(port);}
    template<class D> void setDst(D dst){server.sin_addr.s_addr=inet_addr(dst);}
};

#endif
