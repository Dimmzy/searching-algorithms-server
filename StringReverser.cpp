//
// Created by dima on 1/16/20.
//

#include "StringReverser.h"
#include <algorithm>

std::string StringReverser::solve(std::string problem) {
  reverse(problem.begin(), problem.end());
  return problem;
}