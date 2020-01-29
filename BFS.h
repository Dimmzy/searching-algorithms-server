#ifndef FLIGHTSIMULATORPART2__BFS_H_
#define FLIGHTSIMULATORPART2__BFS_H_

#include "Searcher.h"
#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>
#include "Searchable.h"

/**
 * Breadth First Search implementation, we'll use it to iterate through the graph until we hit our goal node
 * and then return the path traversed.
 * @tparam T The Searchable object we'll find the path of
 * @tparam S The State object that denotes a state in our searchable object.
 */
template<typename S>
class BFS : public Searcher<S> {
 private:
  int numOfNodes;
 public:
  Solution<S> *search(Searchable<S>* searchableItem) override {
    numOfNodes = 0; // Used as a counter to count how many nodes we've checked as a complexity indicator
    std::vector<State<S>*> visited; // Visited nodes
    std::queue<State<S>*> bfsQueue; // Node queue for nodes to check
    /* We mark the initial node as the first node we process and push it to the structures */
    State<S>* init = searchableItem->getInitialState();
    visited.push_back(init);
    bfsQueue.push(init);
    /* While we still have nodes in our queue, we increment the counter and process the nodes */
    while (!bfsQueue.empty()) {
      numOfNodes++;
      State<std::vector<int>> *current = bfsQueue.front();
      bfsQueue.pop();
      /* We found our goal node */
      if (searchableItem->isGoalState(current)) {
        auto* solution = new Solution<S>();
        double sum = 0;
        // Backtrace function
        while(current != init) {
          solution->addNode(current);
          current = current->getPreviousNode();
        }
        solution->setStartingRunningCost(init->getCost());
        solution->setNumOfNodes(numOfNodes);
        return solution;
      }
      // If it's not the goal state, we'll process each of it's neighbors retrieved with getAllPossibleStates
      for (State<S> *node : *searchableItem->getAllPossibleStates(current)) {
        if (std::find(visited.begin(), visited.end(), node) == visited.end()) {
          node->setPreviousNode(current);
          visited.push_back(node);
          bfsQueue.push(node);
        }
      }
    }
    return nullptr;
  }
};

#endif //FLIGHTSIMULATORPART2__BFS_H_
