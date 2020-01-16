#ifndef SEARCHING_ALGORITHMS_SERVER__STRINGREVERSER_H_
#define SEARCHING_ALGORITHMS_SERVER__STRINGREVERSER_H_
#include "Solver.h"
#include <string>

/**
 * StringReverser is a Solver type of class that provides solving logic to the problem of reversing a given string.
 */
 class StringReverser : public Solver<std::string,std::string> {
  public:
   std::string solve(std::string problem) override;
 };

#endif //SEARCHING_ALGORITHMS_SERVER__STRINGREVERSER_H_
