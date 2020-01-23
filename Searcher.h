#ifndef SEARCHER_H_
#define SEARCHER_H_

#include "Searcher.h"
#include "Solution.h"
#include "Searcheable.h"
template <typename T>
class Searcher {
 public:
  virtual Solution<T> search(Searcheable<T> searchableItem) = 0;
};

#endif //SEARCHER_H_
