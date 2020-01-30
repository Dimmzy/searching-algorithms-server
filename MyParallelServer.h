#ifndef SERVER_MYPARALLERSERVER_H_
#define SERVER_MYPARALLERSERVER_H_
#include <netinet/in.h>
#include "Server.h"
#include <thread>
#include <vector>
#include "MyClientHandler.h"

#define MAX_CONNECTIONS 10
#define DEFAULT_PORT 5600

class MyParallelServer : public Server {
 public:
  void open(int port, ClientHandler *client_handler) override;
  void start(int socketfd, sockaddr_in address, ClientHandler *client_handler);
  void stop(int sockfd) override;
  void handleClientFromServer(ClientHandler *client_handler, int sockfd);
  ~MyParallelServer() override;

 private:
  std::vector<std::thread> threadVector;
};

namespace boot {
class Main {
 public:
  static int main(int size, char *args[]) {
    auto *solutionCache = new std::map<std::string, std::string>();
    CacheManager *cacheManager = new FileCacheManager(solutionCache);
    ClientHandler *clientHandler = new MyClientHandler(cacheManager);
    Server *parallelServer = new MyParallelServer();
    if (size == 2) { // Opens the server that will listen on the port that was passed as argument
      parallelServer->open(std::stoi(args[1]), clientHandler);
    } else if (size == 1) { // Opens the server that will listen on the default port specified
      parallelServer->open(DEFAULT_PORT, clientHandler);
    } else {
      std::cout << "Too many arguments passed, exiting!" << std::endl;
      return 1;
    }
    delete solutionCache;
    delete cacheManager;
    delete parallelServer;
    return 0;
  }
};
}

#endif //FLIGHTSIMULATORPART2_SEARCHING_ALGORITHMS_SERVER_MYPARALLERSERVER_H_
