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
 protected:
  std::string runTimeClassName;
 public:
  virtual SOLUTION solve(PROBLEM problem) = 0;
  virtual std::string getName() = 0;
};
#endif //SOLVER_H_