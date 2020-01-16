//
// Created by haim on 14/01/2020.
//

#ifndef MYTESTCLIENTHANDLER_H_
#define MYTESTCLIENTHANDLER_H_

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
#include "StringReverser.h"

class MyTestClientHandler : public ClientHandler{
 private:
  StringReverser solver;
  CacheManager cache_manager;
 public:
  void handleClient(std::istream input_stream, std::ostream output_stream) override;

};

#endif //MYTESTCLIENTHANDLER_H_
