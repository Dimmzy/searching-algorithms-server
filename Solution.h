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
  int numOfNodesTraversed = 0;
  int pathLength = 0;
  int runningCost = 0;
 public:
  Solution<T>() {

  }
  /**
   * Handles creating the solution string we'll send to our client.
   */
  std::string printSolution() {
    std::string solPath;
    // Traverses the path, appending to the string each traversal through the nodes and it's direction and cost.
    for (State<T>* node : this->path) {
      runningCost += node->getCost();
      T* prev = node->getPreviousNode()->getState();
      // Calls direction to append the direction we move in.
      Direction(prev->at(0),node->getState()->at(0),prev->at(1),node->getState()->at(1),node,solPath);
    }
    return solPath;
  }
  void addNode(State<T>* node) {
    this->pathLength++;
    this->path.push_back(node);
  }
  void setNumOfNodes(int nodes) {
    this->numOfNodesTraversed = nodes;
  }
  int getNumofNodes() {
    return this->numOfNodesTraversed;
  }
  int getPathLength() {
    return this->pathLength;
  }

  /**
   * Used to add the initial node cost so we print the correct cost all through
   * @param cost the cost of the initial node (passed through the Algorithm).
   */
  void setStartingRunningCost(int cost) {
    this->runningCost = cost;
  }

  void Direction(int y1, int y2, int x1, int x2,  State<T>* state, std::string& solPath) {
    if (x2 > x1)
      solPath.append("Right (" + std::to_string(this->runningCost) + "), ");
    if (y2 > y1)
      solPath.append("Down (" + std::to_string(this->runningCost) + "), ");
    if (x1 > x2)
      solPath.append("Left (" + std::to_string(this->runningCost) + "), ");
    if (y1 > y2)
      solPath.append("Up (" + std::to_string(this->runningCost) + "), ");
  }

  /**
   * Reverses the path we receive from the solver (since we get it from the end to the start)
   */
  void reversePath() {
    reverse(this->path.begin(), this->path.end());
  }
};

#endif //FLIGHTSIMULATORPART2__SOLUTION_H_
