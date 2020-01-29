
#ifndef FLIGHTSIMULATORPART2__DFS_H_
#define FLIGHTSIMULATORPART2__DFS_H_

#include "Searcher.h"
#include <vector>
#include <stack>

/**
 * Depth First Search implementation, processes less nodes but the path is much longer.
 * @tparam S the data structure we perform DFS on.
 */
template<typename S>
class DFS : public Searcher<S> {
 public:
  Solution<S> *search(Searchable<S> *searchableItem) override {
    int nodesTraversed = 0; // Keeps track of how many nodes we processed
    std::stack<State<S> *> stack; // Stack to handle our traversing nodes
    std::vector<State<S> *> visited; // a vector keeping track of the nodes we already visited
    State<S> *initialNode = searchableItem->getInitialState();
    stack.push(initialNode); // Pushes the starting node to the stack and the visited vector
    visited.push_back(initialNode);
    while (!stack.empty()) {
      State<std::vector<int>> *current = stack.top();
      stack.pop();
      nodesTraversed++;
      /* We reached the goal node */
      if (searchableItem->isGoalState(current)) {
        // Creates new solution, passes path information and returns it to the object adapter that called the function.
        auto *solution = new Solution<S>();
        solution->setNumOfNodes(nodesTraversed);
        solution->setStartingRunningCost(initialNode->getCost());
        while (current != initialNode) {
          solution->addNode(current);
          current = current->getPreviousNode();
        }
        return solution;
      }
      /* For each neighbor of the current node, if we still haven't visited it,
       * we push it to the visited queue and process it */
      for (State<S> *neighbor : *searchableItem->getAllPossibleStates(current)) {
        if (std::find(visited.begin(), visited.end(), neighbor) == visited.end()) {
          neighbor->setPreviousNode(current);
          stack.push(neighbor);
          visited.push_back(neighbor);
        }
      }
    }
  }
};

#endif //FLIGHTSIMULATORPART2__DFS_H_
