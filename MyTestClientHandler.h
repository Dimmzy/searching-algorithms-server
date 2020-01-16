#ifndef MYTESTCLIENTHANDLER_H_
#define MYTESTCLIENTHANDLER_H_

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"

class MyTestClientHandler : public ClientHandler{
 private:
  Solver solver;
  CacheManager* cache_manager;
};

#endif //MYTESTCLIENTHANDLER_H_
