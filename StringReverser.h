//
// Created by dima on 1/16/20.
//

#ifndef SEARCHING_ALGORITHMS_SERVER__STRINGREVERSER_H_
#define SEARCHING_ALGORITHMS_SERVER__STRINGREVERSER_H_
#include "Solver.h"
#include <string>

 class StringReverser : public Solver<std::string,std::string> {
  public:
   std::string solve(std::string problem) override;
 };

#endif //SEARCHING_ALGORITHMS_SERVER__STRINGREVERSER_H_
