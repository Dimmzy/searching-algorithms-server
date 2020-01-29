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

namespace boot {
class Main {
 public:
  static int main(int size, char *args[]) {
    /*
    Solver<std::string,std::string>* string_reverser = new StringReverser();
    CacheManager *file_cache_manager = new FileCacheManager("StringReverser");
    ClientHandler* my_test_client_handler = new MyTestClientHandler(string_reverser, file_cache_manager);
    Server* my_serial_server = new MySerialServer();
    my_serial_server->open(std::stoi(args[1]), my_test_client_handler);
    return 0;
     */
    auto* solutionCache = new std::map<std::string, std::string>();
    CacheManager *file_cache_manager = new FileCacheManager(solutionCache);
    ClientHandler* ch = new MyClientHandler(file_cache_manager);
    Server* my_paraller_server = new MyParallerServer();
    my_paraller_server->open(std::stoi(args[1]), ch);
    return 0;
  }
};
}

#endif //FLIGHTSIMULATORPART2_SEARCHING_ALGORITHMS_SERVER_MYPARALLERSERVER_H_
