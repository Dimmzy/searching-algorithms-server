#ifndef OBJECTADAPTER_H_
#define OBJECTADAPTER_H_

#include "Solver.h"
#include "Searchable.h"
#include "Searcher.h"
#include "Matrix.h"
#include "DFS.h"
#include <vector>
template <typename T>
class ObjectAdapter : public Solver<Searchable<T> *, std::string> {
 public:

  ObjectAdapter<T>(Searcher<T>* searcher) {
    this->searcher = searcher;
  }
  virtual std::string solve(Searchable<T>* problem) {
    Solution<T>* sol = this->searcher->search(problem);
  }
  virtual std::string getName() {
    this->searcher->getName();
  }
 private:
  Searcher<T>* searcher;
};

#endif //OBJECTADAPTER_H_