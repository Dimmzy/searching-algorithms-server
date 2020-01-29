
#ifndef FLIGHTSIMULATORPART2__DFS_H_
#define FLIGHTSIMULATORPART2__DFS_H_

#include "Searcher.h"
#include <vector>
#include <stack>

template<typename S>
class DFS : public Searcher<S> {

 public:
  Solution<S> *search(Searchable<S> *searchableItem) override {
    int nodesTraversed = 0;
    std::stack<State<S> *> stack;
    std::vector<State<S> *> visited;
    State<S> *initialNode = searchableItem->getInitialState();
    stack.push(initialNode);
    visited.push_back(initialNode);
    while (!stack.empty()) {
      State<std::vector<int>> *current = stack.top();
      stack.pop();
      nodesTraversed++;
      if (searchableItem->isGoalState(current)) {
        auto *solution = new Solution<S>();
        solution->setNumOfNodes(nodesTraversed);
        solution->setStartingRunningCost(initialNode->getCost());
        while (current != initialNode) {
          solution->addNode(current);
          current = current->getPreviousNode();
        }
        return solution;
      }
      for (State<S> *neighbor : *searchableItem->getAllPossibleStates(current)) {
        if (std::find(visited.begin(), visited.end(), neighbor) == visited.end()) {
          neighbor->setPreviousNode(current);
          stack.push(neighbor);
          visited.push_back(neighbor);
        }
      }
    }
  }

  std::string getName() override {
    return std::__cxx11::string();
  }

};

#endif //FLIGHTSIMULATORPART2__DFS_H_
