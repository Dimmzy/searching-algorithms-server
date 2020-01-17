#include <iostream>
#include "MyTestClientHandler.h"
#include "MySerialServer.h"
#include "Solver.h"
#include <thread>


#include <arpa/inet.h>
int main(int size, char* args[]) {
  boot::Main::main(size, args);

  int client_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (client_socket == -1)
    std::cerr << "Couldn't create client socket" << std::endl;
  struct sockaddr_in address{};
  address.sin_family = AF_INET;
  const char* ip = "127.0.0.1";
  address.sin_addr.s_addr = inet_addr(ip);
  address.sin_port = htons(5600);
  int is_connect = connect(client_socket, (struct sockaddr *)&address, sizeof(address));
  if (is_connect == -1)
    std::cerr << "Couldn't connect to host" << std::endl;

  std::cout << "Client Opened Successfully" << std::endl;

  char a[] = "abcde";
  int is_sent = send(client_socket, a, 6, 0);
  if(is_sent == -1) {
    std::cout<<"Error sending message"<<std::endl;
  }
  else {
    std::cout<<"Message was sent successfully"<<std::endl;
  }
}

