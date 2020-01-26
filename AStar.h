
#ifndef FLIGHTSIMULATORPART2__ASTAR_H_
#define FLIGHTSIMULATORPART2__ASTAR_H_
#include "Searcher.h"
#include <vector>
#include <queue>



template <typename T, typename S>
class AStar : public Searcher<T,S> {
 public:
  Solution<S> *search(Searchable<T> *searchableItem) override {
    std::vector<State<T>*> openList;
    std::vector<State<T>*> closedList;
    openList.push_back()


  }

  std::string getName() override {
    return std::__cxx11::string();
  }
};

#endif //FLIGHTSIMULATORPART2__ASTAR_H_
