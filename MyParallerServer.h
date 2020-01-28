#ifndef SERVER_MYPARALLERSERVER_H_
#define SERVER_MYPARALLERSERVER_H_
#include <netinet/in.h>
#include "Server.h"
#include <thread>
#include <vector>
#include "MyClientHandler.h"
#define MAX_CONNECTIONS 10
class MyParallerServer :public Server{
 public:
  void open(int port, ClientHandler* client_handler) override;
  void start(int socketfd, sockaddr_in address, ClientHandler* client_handler);
  void stop(int sockfd) override;
  void handleClientFromServer(ClientHandler* client_handler, int sockfd);
  ~MyParallerServer();

 private:
  std::vector<std::thread> threadVector;
};

#endif //FLIGHTSIMULATORPART2_SEARCHING_ALGORITHMS_SERVER_MYPARALLERSERVER_H_
