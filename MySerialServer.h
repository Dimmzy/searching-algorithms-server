//
// Created by haim on 15/01/2020.
//


#ifndef MYSERIALSERVER_H_
#define MYSERIALSERVER_H_

#include "Server.h"
#include "MyClientHandler.h"
#include <queue>
#include <netinet/in.h>
#include <thread>
#include <unistd.h>
#include <arpa/inet.h>
#include <iostream>

class MySerialServer : public Server {
 public:
  void open(int port, ClientHandler* client_handler) override;
  void start(int socketfd, sockaddr_in address, ClientHandler* client_handler);
  void stop(int sockfd) override;
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
    /*
    ClientHandler* ch = new MyClientHandler();
    Server* my_serial_server = new MySerialServer();
    my_serial_server->open(std::stoi(args[1]), ch);
     */
    return 0;
  }
};
}

#endif //FLIGHTSIMULATORPART2__MYSERIALSERVER_H_
