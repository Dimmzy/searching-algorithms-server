#ifndef SEARCHER_H_
#define SEARCHER_H_

#include "Searcher.h"
#include "Solution.h"
template <typename T>
class Searcher{
 public:
  virtual Solution search(Searchable<T> searchableItem) = 0;
};

#endif //SEARCHER_H_
