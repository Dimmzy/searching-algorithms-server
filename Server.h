//
// Created by haim on 14/01/2020.
//

#ifndef SERVER_H_
#define SERVER_H_

#include "ClientHandler.h"
class Server {
 public:
  int open(int port, ClientHandler client_handler);
  void stop();
};

#endif //SERVER_H_
