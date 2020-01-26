
#ifndef FLIGHTSIMULATORPART2__ASTAR_H_
#define FLIGHTSIMULATORPART2__ASTAR_H_
#include "Searcher.h"
#include <vector>
#include <queue>



template <typename T>
class AStar : public Searcher<T> {
 public:
  Solution<T> *search(Searchable<T> *searchableItem) override {
    std::priority_queue<State<T>*>


  }

  std::string getName() override {
    return std::__cxx11::string();
  }
};

#endif //FLIGHTSIMULATORPART2__ASTAR_H_
