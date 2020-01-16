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
  ~MySerialServer();
  int open(int port, ClientHandler client_handler);
  void start(int socketfd, sockaddr_in address);
};

#endif //FLIGHTSIMULATORPART2__MYSERIALSERVER_H_
