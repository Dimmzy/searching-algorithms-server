//
// Created by haim on 14/01/2020.
//

#ifndef MYTESTCLIENTHANDLER_H_
#define MYTESTCLIENTHANDLER_H_

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
#include "StringReverser.h"
#include "FileCacheManager.h"
#include <cstring>

class MyTestClientHandler : public ClientHandler {
 private:
  Solver<std::string , std::string>* solver;
  CacheManager* cache_manager;
 public:
  void handleClient(int input_stream, int output_stream) override;
  MyTestClientHandler(Solver<std::string , std::string>* string_reverser, CacheManager* cache_manager);
};

#endif //MYTESTCLIENTHANDLER_H_
