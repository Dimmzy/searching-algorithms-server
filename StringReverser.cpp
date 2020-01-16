#include "StringReverser.h"
#include <algorithm>

/**
 * Reverses that string using a built in C++ library.
 * @param problem the string we want to reverse
 * @return the reversed string
 */
std::string StringReverser::solve(std::string problem) {
  // Using built-in reversal function from <algorithm> library
  reverse(problem.begin(), problem.end());
  return problem;
}