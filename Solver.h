#ifndef SOLVER_H_
#define SOLVER_H_
template <class PROBLEM, class SOLUTION>
class Solver {
 protected:
  std::string runTimeClassName;
 public:
  virtual std::string getRunTimeClassName() = 0;
  virtual SOLUTION solve(PROBLEM problem) = 0;
  virtual void setRunTimeClassName(std::string name) = 0;
};
#endif //SOLVER_H_
