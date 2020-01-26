
#ifndef FLIGHTSIMULATORPART2__ASTAR_H_
#define FLIGHTSIMULATORPART2__ASTAR_H_
#include "Searcher.h"
#include <vector>
#include <queue>



template <typename T, typename S>
class AStar : public Searcher<T,S> {
 public:
  Solution<S> *search(Searchable<T> *searchableItem) override {
    std::priority_queue<State<S>*>


  }

  std::string getName() override {
    return std::__cxx11::string();
  }
};

#endif //FLIGHTSIMULATORPART2__ASTAR_H_
