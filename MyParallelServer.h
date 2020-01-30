#ifndef SERVER_MYPARALLERSERVER_H_
#define SERVER_MYPARALLERSERVER_H_
#include <netinet/in.h>
#include "Server.h"
#include <thread>
#include <vector>
#include "MyClientHandler.h"
#define MAX_CONNECTIONS 10
class MyParallelServer : public Server {
 public:
  void open(int port, ClientHandler *client_handler) override;
  void start(int socketfd, sockaddr_in address, ClientHandler *client_handler);
  void stop(int sockfd) override;
  void handleClientFromServer(ClientHandler *client_handler, int sockfd);
  ~MyParallelServer();

 private:
  std::vector<std::thread> threadVector;
};

namespace boot {
class Main {
 public:
  static int main(int size, char *args[]) {
    auto* solutionCache = new std::map<std::string, std::string>();
    CacheManager *file_cache_manager = new FileCacheManager(solutionCache);
    ClientHandler *ch = new MyClientHandler(file_cache_manager);
    Server *my_paraller_server = new MyParallelServer();
    my_paraller_server->open(std::stoi(args[1]), ch);
    delete solutionCache;
    delete file_cache_manager;
    delete my_paraller_server;
    return 0;
  }
};
}

#endif //FLIGHTSIMULATORPART2_SEARCHING_ALGORITHMS_SERVER_MYPARALLERSERVER_H_