//
// Created by haim on 14/01/2020.
//

#ifndef SOLVER_H_
#define SOLVER_H_
template <class PROBLEM, class SOLUTION>
class Solver {
 public:
  virtual SOLUTION solve(PROBLEM problem) = 0;
  virtual std::string getProblemDescription() = 0;
  virtual std::string getSolutionDescription() = 0;
};
#endif //SOLVER_H_
