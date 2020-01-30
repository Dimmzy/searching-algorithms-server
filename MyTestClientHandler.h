#ifndef MYTESTCLIENTHANDLER_H_
#define MYTESTCLIENTHANDLER_H_

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
#include "StringReverser.h"
#include "FileCacheManager.h"
#include <cstring>
#include "algorithm"
#include <unistd.h>
#include <sys/socket.h>

class MyTestClientHandler : public ClientHandler {
 private:
  Solver<std::string, std::string> *solver; //The responsible class for solving the problems of the client
  CacheManager *cManager; //The database that keeps the solution for problems we have seen before
 public:
  void handleClient(int input_stream, int output_stream) override;
  MyTestClientHandler(Solver<std::string, std::string> *string_reverser, CacheManager *cacheManager);
};

#endif //MYTESTCLIENTHANDLER_H_