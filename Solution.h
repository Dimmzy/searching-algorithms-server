//
// Created by haim on 20/01/2020.
//

#ifndef FLIGHTSIMULATORPART2__SOLUTION_H_
#define FLIGHTSIMULATORPART2__SOLUTION_H_
#include <vector>
#include <algorithm>
#include "State.h"
#include <iostream>

template <typename T>
class Solution {
 private:
  std::vector<State<T>*> path;
  int numOfNodesTraversed;
  double costFromInitial;
 public:
  void printNodes() {
    for (State<T>* node : this->path) {
      costFromInitial += node->getCost();
      node->setCostFromInitial(costFromInitial);
      T* prev = node->getPreviousNode()->getState();
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
  void reversePath() {
    reverse(this->path.begin(), this->path.end());
  }
};

#endif //FLIGHTSIMULATORPART2__SOLUTION_H_
