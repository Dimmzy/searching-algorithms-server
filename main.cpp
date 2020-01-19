#include <sys/socket.h>
#include <iostream>
#include "MyTestClientHandler.h"
#include "MySerialServer.h"
#include "Solver.h"
#include <thread>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int size, char *args[]) {
  boot::Main::main(size, args);
  int client_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (client_socket == -1)
    std::cerr << "Couldn't create client socket" << std::endl;
  sockaddr_in address;
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = inet_addr("127.0.0.1");
  address.sin_port = htons(6500);
  int is_connect = connect(client_socket, (struct sockaddr *) &address, sizeof(address));
  if (is_connect == -1)
    std::cerr << "Couldn't connect to host" << std::endl;
  std::cout << "Client Opened Successfully" << std::endl;
  char a[] = "HELLO FROM CLIENT";
  int is_sent = send(client_socket, a, sizeof(a), 0);
  if (is_sent == -1) {
    std::cout << "Error sending message" << std::endl;
  } else {
    std::cout << "Message was sent successfully" << std::endl;
  }
  char buffer[1024] = {0};
  int valread = read(client_socket,buffer,1024);
  std::cout<<buffer<<std::endl;
  close(client_socket);
}

