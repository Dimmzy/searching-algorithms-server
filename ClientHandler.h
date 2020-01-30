#ifndef CLIENTHANDLER_H_
#define CLIENTHANDLER_H_

#include <iostream>

/**
 * The ClientHandler handles receiving information through socket streams and moving them through to find a solution.
 */
class ClientHandler {
 public:
  virtual void handleClient(int input_stream, int output_stream) = 0;
  virtual ~ClientHandler() = default;
};

#endif //CLIENTHANDLER_H_
