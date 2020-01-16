//
// Created by haim on 14/01/2020.
//

#ifndef CLIENTHANDLER_H_
#define CLIENTHANDLER_H_


#include <iostream>
class ClientHandler {

 protected:
  int port;
 public:
  virtual void handleClient(std::istream input_stream, std::ostream output_stream) = 0;
};

#endif //CLIENTHANDLER_H_
