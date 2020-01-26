
#ifndef FLIGHTSIMULATORPART2__BFS_H_
#define FLIGHTSIMULATORPART2__BFS_H_
#include "Searcher.h"
#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>

template<typename T, typename S>
class BFS : public Searcher<T,S> {
 public:
  Solution<S> *search(Matrix *searchableItem) override {
    std::vector<State<S>*> visited;
    std::queue<State<S>*> bfsQueue;
    State<S>* init = searchableItem->getInitialState();
    visited.push_back(init);
    bfsQueue.push(init);
    while (!bfsQueue.empty()) {
      State<std::vector<int>> *current = bfsQueue.front();
      bfsQueue.pop();
      if (searchableItem->isGoalState(current)) {
        auto solution = new Solution<S>();
        while(current != init) {
          std::cout << current->getCost();
          std::cout << "->";
          current = current->getPreviousNode();
        }
        return solution;
      }
      for (State<S> *node : searchableItem->getAllPossibleStates(current)) {
        if (std::find(visited.begin(), visited.end(), node) != visited.end()) {
          visited.push_back(current);
          node->setPreviousNode(current);
          bfsQueue.push(node);
        }
      }
    }
  }
  std::string getName() override {
    return "BFS";
  }
};

#endif //FLIGHTSIMULATORPART2__BFS_H_
