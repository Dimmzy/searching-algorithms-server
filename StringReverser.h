//
// Created by haim on 16/01/2020.
//

#ifndef STRINGREVERSER_H_
#define STRINGREVERSER_H_

#include <string>
#include "Solver.h"

 class StringReverser : public Solver<std::string, std::string> {
 private:
  std::string solverName = "StringReverser";
 public:
  std::string solve(std::string problem) override;
  std::string getName() override;
};

#endif //STRINGREVERSER_H_
