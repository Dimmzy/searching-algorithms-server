#ifndef SEARCHER_H_
#define SEARCHER_H_

#include "Searcher.h"
#include "Solution.h"
#include "Searchable.h"
#include "Matrix.h"

template <typename T, typename S>
class Searcher {
 public:
  virtual std::string getName() = 0;
  virtual Solution<S>* search(Matrix* searchableItem) = 0;
};

#endif //SEARCHER_H_
