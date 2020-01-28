#ifndef STRINGREVERSER_H_
#define STRINGREVERSER_H_

#include <string>
#include "Solver.h"

/**
 * A solver that receives a string and reverses it (hello -> olleh, etc...)
 */
 class StringReverser : public Solver<std::string, std::string> {
 public:
  std::string solve(std::string problem) override;
};

#endif //STRINGREVERSER_H_
