#ifndef SERVER_H_
#define SERVER_H_

#include "ClientHandler.h"
#include "MyTestClientHandler.h"

class Server {
 public:
  virtual void open(int port, ClientHandler* client_handler) = 0;
  virtual void stop(int sockfd) = 0;
};

#endif //SERVER_H_