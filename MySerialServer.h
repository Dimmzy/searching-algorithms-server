//
// Created by haim on 15/01/2020.
//


#ifndef MYSERIALSERVER_H_
#define MYSERIALSERVER_H_

#include "Server.h"
#include <queue>
#include <netinet/in.h>
#include <thread>

class MySerialServer : public Server {
 public:
  void openServer(int port);
  int open(int port, ClientHandler* client_handler);
  void start(int socketfd, sockaddr_in address, ClientHandler* client_handler);
  void stop(int sockfd);
};


namespace boot {
class Main {
 public:
  static int main(int size, char* args[]) {
    CacheManager *file_cache_manager = new FileCacheManager();
    Solver<std::string,std::string>* string_reverser = new StringReverser();
    ClientHandler* my_test_client_handler = new MyTestClientHandler(string_reverser, file_cache_manager);
    Server* my_serial_server = new MySerialServer();
    my_serial_server->open(6500, my_test_client_handler);
  }
};
}

#endif //FLIGHTSIMULATORPART2__MYSERIALSERVER_H_
