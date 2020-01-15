//
// Created by haim on 14/01/2020.
//

#ifndef SOLVER_H_
#define SOLVER_H_
template <class PROBLEM, class SOLUTION>
class Solver {
 public:
  SOLUTION solve(PROBLEM problem);
};
#endif //SOLVER_H_
