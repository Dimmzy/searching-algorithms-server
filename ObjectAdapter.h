#ifndef OBJECTADAPTER_H_
#define OBJECTADAPTER_H_

#include "Solver.h"
#include "Searchable.h"
#include "Searcher.h"
#include "Matrix.h"
#include <vector>

/**
 * The ObjectAdapter handles passing our Searchable Objects onto a Searcher that solves the problem given.
 * It then receives the solution, adapts it into a string we can then send as a solution to the client handler, which
 * in turn sends it to the client.
 * @tparam T The Searchable Object template type.
 * @tparam S The State object template type.
 */
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