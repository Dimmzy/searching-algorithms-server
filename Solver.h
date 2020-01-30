#ifndef SOLVER_H_
#define SOLVER_H_

#include <string>

/**
 * The Solver interface handles solving problems and providing solutions to them through a Solution object.
 * @tparam PROBLEM
 * @tparam SOLUTION
 */
template <class PROBLEM, class SOLUTION>
class Solver {
 public:
  virtual SOLUTION solve(PROBLEM problem) = 0;
  virtual ~Solver() = default;
};
#endif //SOLVER_H_