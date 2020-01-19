#include "MySerialServer.h"

/**
 * A function that open the socket with the server
 * @param port The port
 * @param client_handler The client which his problems we need to solve
 */
void MySerialServer::open(int port, ClientHandler *client_handler) {
  int socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if (socketfd == -1)
    std::cerr << "Couldn't create socket" << std::endl;

  struct timeval tv = {};
  tv.tv_sec = 30;
  tv.tv_usec = 0;
  setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char *) &tv, sizeof(tv));

  sockaddr_in address = {};
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(port);
  if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1)
    std::cerr << "Couldn't bind socket to IP" << std::endl;
  if (listen(socketfd, 1) == -1)
    std::cerr << "Couldn't listen to socket" << std::endl;
  else
    std::cout << "Waiting for clients to connect" << std::endl;
  std::thread thread2(&MySerialServer::start, this, socketfd, address, client_handler);
  thread2.join();
}

/**
 * A function that accepts one client at time and call to handleClient method whose responsibility his to solve the
 * clients' problems.
 * @param socketfd The file descriptor of the socket with the server
 * @param address The address of the socket of the sever (IPV4, localhost, port)
 * @param client_handler The object that represents the client.
 */
void MySerialServer::start(int socketfd, sockaddr_in address, ClientHandler *client_handler) {
  while(true) {
    int client_socket = accept(socketfd, (struct sockaddr *) &address, (socklen_t *) &address);
    if (client_socket < 0) {
      if (errno == EWOULDBLOCK) {
        std::cout << "timeout!" << std::endl;
        break;
      }
      else {
        std::cerr << "Error accepting connection" << std::endl;
        std::cout << strerror(errno);
        break;
      }
    }
    else {
      std::cout << "Connected" << std::endl;
      client_handler->handleClient(client_socket, client_socket);
    }
  }
  this->stop(socketfd);
}

/**
 * A function that close the socket with the server.
 * @param sockfd The socket with the server.
 */
void MySerialServer::stop(int sockfd) {
  close(sockfd);
}