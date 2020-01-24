#ifndef OBJECTADAPTER_H_
#define OBJECTADAPTER_H_

#include "Solver.h"
#include "Searchable.h"
#include "Searcher.h"

template<typename T, typename P, typename S>

class ObjectAdapter : public Solver<P, S> {
 public:
  S solve(P problem) override;
  std::string getName() override;
 private:
  Searchable<T> searchable;
  Searcher<T> searcher;
};

#endif //OBJECTADAPTER_H_
