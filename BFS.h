
#ifndef FLIGHTSIMULATORPART2__BFS_H_
#define FLIGHTSIMULATORPART2__BFS_H_

#include "Searcher.h"
#include <queue>


template <typename T>
class BFS : public Searcher<T> {
 public:
  Solution<T> search(Searchable<T>* searchableItem) override;
};


#endif //FLIGHTSIMULATORPART2__BFS_H_
