//
// Created by haim on 16/01/2020.
//

#ifndef STRINGREVERSER_H_
#define STRINGREVERSER_H_

#include <string>
#include "Solver.h"

 class StringReverser : public Solver<std::string, std::string> {
 public:
  std::string solve(std::string problem) override;
};

#endif //STRINGREVERSER_H_
