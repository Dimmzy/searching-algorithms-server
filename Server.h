#ifndef SERVER_H_
#define SERVER_H_

#include "ClientHandler.h"
#include "MyTestClientHandler.h"

/**
 * The server class provides an interface to handle opening and closing sockets to handle clients
 */
class Server {
 public:
  virtual void open(int port, ClientHandler* client_handler) = 0;
  virtual void stop(int sockfd) = 0;
  virtual ~Server() = default;
};

#endif //SERVER_H_