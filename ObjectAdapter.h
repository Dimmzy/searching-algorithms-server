#ifndef OBJECTADAPTER_H_
#define OBJECTADAPTER_H_

#include "Solver.h"
#include "Searchable.h"
#include "Searcher.h"
#include "Matrix.h"
#include <vector>
template <typename T,typename S>
class ObjectAdapter : public Solver<Searchable<T> *, std::string> {
 public:

  ObjectAdapter<T,S>(Searcher<T,S>* searcher) {
    this->searcher = searcher;
  }
  virtual std::string solve(Searchable<T>* problem) {
    Solution<T>* sol = this->searcher->search(problem);
  }
  virtual std::string getName() {
    this->searcher->getName();
  }
 private:
  Searcher<T,S>* searcher;
};

#endif //OBJECTADAPTER_H_