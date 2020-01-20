#ifndef SOLVER_H_
#define SOLVER_H_
template <class PROBLEM, class SOLUTION>
class Solver {
 protected:
  std::string runTimeClassName;
 public:
  virtual SOLUTION solve(PROBLEM problem) = 0;
  virtual std::string getName() = 0;
};
#endif //SOLVER_H_
