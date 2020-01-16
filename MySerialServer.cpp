//
// Created by haim on 15/01/2020.
//

#include "MySerialServer.h"
static bool is_done = false;

int MySerialServer::open(int port, ClientHandler client_handler) {
  int socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if (socketfd == -1)
    std::cerr << "Couldn't create socket" << std::endl;

  struct timeval tv;
  tv.tv_sec = 20*60;
  setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof(tv));

  sockaddr_in address;
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(port);
  if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1)
    std::cerr << "Couldn't bind socket to IP" << std::endl;
  if (listen(socketfd, 10) == -1)
    std::cerr << "Couldn't listen to socket" << std::endl;
  std::thread(&MySerialServer::start, this, socketfd, address);


}


void MySerialServer::start(int socketfd, sockaddr_in address) {
  int client_socket;
  while (!is_done) {
    client_socket = accept(socketfd, (struct sockaddr *) &address, (socklen_t *) &address);
    if (client_socket == -1)
      std::cerr << "Couldn't accept client" << std::endl;
    else {
      std::cout << "Connected" << std::endl;
      is_done = true;
    }
  }
}
