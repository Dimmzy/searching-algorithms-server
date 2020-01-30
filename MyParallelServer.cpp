#include "MyParallelServer.h"

/**
 * A function that open the socket with the server
 * @param port The port
 * @param client_handler The client which his problems we need to solve
 */
void MyParallelServer::open(int port, ClientHandler *client_handler) {
  int socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if (socketfd == -1)
    std::cerr << "Couldn't create socket" << std::endl;

  sockaddr_in address = {};
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(port);
  if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1)
    std::cerr << "Couldn't bind socket to IP" << std::endl;
  if (listen(socketfd, MAX_CONNECTIONS) == -1)
    std::cerr << "Couldn't listen to socket" << std::endl;
  else
    std::cout << "Waiting for clients to connect" << std::endl;

  struct timeval tv = {};
  tv.tv_sec = 30;
  tv.tv_usec = 0;
  setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char *) &tv, sizeof(tv));
  this->start(socketfd, address, client_handler);
}

void MyParallelServer::start(int socketfd, sockaddr_in address, ClientHandler *client_handler) {
  int client_socket;
  while (true) {
    client_socket = accept(socketfd, (struct sockaddr *) &address, (socklen_t *) &address);
    if (client_socket < 0) {
      if (errno == EWOULDBLOCK) {
        std::cout << "timeout!" << std::endl;
        break;
      } else {
        std::cerr << "Error accepting connection" << std::endl;
        std::cout << strerror(errno);
        break;
      }
    }
    else {
      std::cout << "Connected" << std::endl;
      this->threadVector.emplace_back(std::thread(&MyParallelServer::handleClientFromServer, this, client_handler,
                                                  client_socket));
      //client_handler->handleClient(client_socket, client_socket);
    }
  }
  this->stop(socketfd);
}

void MyParallelServer::handleClientFromServer(ClientHandler *client_handler, int sockfd) {
  client_handler->handleClient(sockfd, sockfd);
}

void MyParallelServer::stop(int sockfd) {
  close(sockfd);
}
MyParallelServer::~MyParallelServer() {
  for (auto &i : this->threadVector) {
    i.join();
  }
}
