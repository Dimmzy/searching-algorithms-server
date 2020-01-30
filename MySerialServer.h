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


#endif //FLIGHTSIMULATORPART2__MYSERIALSERVER_H_
