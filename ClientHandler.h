//
// Created by haim on 14/01/2020.
//

#ifndef CLIENTHANDLER_H_
#define CLIENTHANDLER_H_


#include <iostream>
class ClientHandler {

 public:
  virtual void handleClient(int input_stream, int output_stream) = 0;
};

#endif //CLIENTHANDLER_H_
