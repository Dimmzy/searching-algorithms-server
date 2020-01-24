
#ifndef FLIGHTSIMULATORPART2__MYCLIENTHANDLER_H_
#define FLIGHTSIMULATORPART2__MYCLIENTHANDLER_H_

#include "ClientHandler.h"
#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
#include "StringReverser.h"
#include "FileCacheManager.h"
#include "State.h"
#include <cstring>
#include <algorithm>
#include <unistd.h>
#include <sys/socket.h>
#include <vector>

class MyClientHandler : public ClientHandler{
 public:
  void handleClient(int input_stream, int output_stream) override;
 private:
  static void rmLinebreak(std::string& str);
};

#endif //FLIGHTSIMULATORPART2__MYCLIENTHANDLER_H_
