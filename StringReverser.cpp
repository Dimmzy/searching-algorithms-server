//
// Created by haim on 16/01/2020.
//

#include "StringReverser.h"
#include <algorithm>

std::string StringReverser::solve(std::string problem) {
  // Using built-in reversal function from <algorithm> library
  reverse(problem.begin(), problem.end());
  return problem;
}

std::string StringReverser::getRunTimeClassName() {
  return this->runTimeClassName;
}
void StringReverser::setRunTimeClassName(const std::string name) {
  this->runTimeClassName = name;
}
