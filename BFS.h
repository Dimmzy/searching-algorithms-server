
#ifndef FLIGHTSIMULATORPART2__BFS_H_
#define FLIGHTSIMULATORPART2__BFS_H_
#include "Searcher.h"
#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>

template<typename T, typename S>
class BFS : public Searcher<T,S> {
 private:
  int numOfNodes;
 public:
  Solution<S> *search(Matrix *searchableItem) override {
    numOfNodes = 0;
    std::vector<State<S>*> visited;
    std::queue<State<S>*> bfsQueue;
    State<S>* init = searchableItem->getInitialState();
    visited.push_back(init);
    bfsQueue.push(init);
    while (!bfsQueue.empty()) {
      numOfNodes++;
      State<std::vector<int>> *current = bfsQueue.front();
      bfsQueue.pop();
      if (searchableItem->isGoalState(current)) {
        auto solution = new Solution<S>();
        double sum = 0;
        while(current != init) {
          sum += current->getCost();
          std::cout << current->getCost();
          std::cout << "->";
          current = current->getPreviousNode();
        }
        std::cout << std::endl;
        std::cout << "Total sum is : " + std::to_string(sum) << std::endl;
        std::cout << "Total traversed is : " + std::to_string(numOfNodes) << std::endl;
        return solution;
      }
      for (State<S> *node : *searchableItem->getAllPossibleStates(current)) {
        if (std::find(visited.begin(), visited.end(), node) == visited.end()) {
          node->setPreviousNode(current);
          visited.push_back(node);
          bfsQueue.push(node);
        }
      }
    }
  }
  std::string getName() override {
    return "BFS";
  }

  int getNumOfNodes() {
    return this->numOfNodes;
  }
};

#endif //FLIGHTSIMULATORPART2__BFS_H_
