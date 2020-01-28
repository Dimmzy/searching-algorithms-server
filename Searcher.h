#ifndef SEARCHER_H_
#define SEARCHER_H_

#include "Searcher.h"
#include "Solution.h"
#include "Searchable.h"
#include "Matrix.h"

/**
 * The Searcher Interface defines a class that can search through a searchable object to find a solution.
 * @tparam T
 * @tparam S
 */
template <typename T, typename S>
class Searcher {
 public:
  virtual Solution<S>* search(T* searchableItem) = 0;
};

#endif //SEARCHER_H_
