#ifndef FLIGHTSIMULATORPART2__SOLUTION_H_
#define FLIGHTSIMULATORPART2__SOLUTION_H_

#include <vector>
#include <algorithm>
#include "State.h"
#include <iostream>

/**
 * The Solution class handles converting output from a Solver function into user friendly format that we can send back
 * to the client.
 * @tparam T The State object we handled in our pathing algorithms.
 */

template <typename T>
class Solution {
 private:
  std::vector<State<T>*> path;
  int numOfNodesTraversed;
  double costFromInitial;
 public:
  /**
   * Handles creating the solution string we'll send to our client.
   */
  void printNodes() {
    // Traverses the path, appending to the string each traversal through the nodes and it's direction and cost.
    for (State<T>* node : this->path) {
      costFromInitial += node->getCost();
      //node->setCostFromInitial(costFromInitial);
      T* prev = node->getPreviousNode()->getState();
      // Calls direction to append the direction we move in.
      Direction(prev->at(0),node->getState()->at(0),prev->at(1),node->getState()->at(1),node);
    }
    std::cout << std::endl;
  }
  void addNode(State<T>* node) {
    this->path.push_back(node);
  }
  void setNumOfNodes(int nodes) {
    this->numOfNodesTraversed = nodes;
  }
  void setInitialCost(double cost) {
    this->costFromInitial = cost;
  }
  void Direction(int y1, int y2, int x1, int x2,  State<T>* state) {
    if (x2 > x1)
      std::cout << "Right (" + std::to_string(state->getCostFromInitial()) + "), ";
    if (y2 > y1)
      std::cout << "Down (" + std::to_string(state->getCostFromInitial()) + "), ";
    if (x1 > x2)
      std::cout << "Left (" + std::to_string(state->getCostFromInitial()) + "), ";
    if (y1 > y2)
      std::cout << "Up (" + std::to_string(state->getCostFromInitial()) + "), ";
  }

  /**
   * Reverses the path we receive from the solver (since we get it from the end to the start)
   */
  void reversePath() {
    reverse(this->path.begin(), this->path.end());
  }
};

#endif //FLIGHTSIMULATORPART2__SOLUTION_H_
