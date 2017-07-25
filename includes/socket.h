#ifndef SOCKET_H
#define SOCKET_H
#include<sys/socket.h>
#include<netinet/tcp.h>   
#include<netinet/ip.h>
#include <arpa/inet.h>
#define TCP 0x01
#define UDP 0x02


template<char const P> class Socket;
template<>
class Socket<TCP> {
  private:
    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    char datagram[4096];
    struct sockaddr_in server;
    server.sin_family=AF_INET;
    
public:

    template <class D> Socket(D dst, int port){
      server.sin_addr.s_addr=inet_addr(dst);
      server.sin_port=htons(port);
      connect(sock , (struct sockaddr *)&server , sizeof(server));}
      
    void setPort(int port){server.sin_port=htons(port);}
    template<class D> void setDst(D dst){server.sin_addr.s_addr=inet_addr(dst);}
    char* recieve(char* buf, size_t max){
      int bytesRecieved = 0, totalBytesRecieved = 0;
      while (!((bytesRecieved=recv(sock, buf, 65535, MSG_DONTWAIT))<=0)){totalBytesRecieved += bytesRecieved;}}
};

#endif
