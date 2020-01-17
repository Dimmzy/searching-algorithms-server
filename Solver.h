#ifndef SOLVER_H_
#define SOLVER_H_
template <class PROBLEM, class SOLUTION>
class Solver {
 public:
  virtual SOLUTION solve(PROBLEM problem) = 0;
};
#endif //SOLVER_H_
