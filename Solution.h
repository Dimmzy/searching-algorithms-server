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
 public:
  void printNodes() {
    double sum = 0;
    for (State<T>* node : this->path) {
      sum += node->getCost();
      std::cout << node->getCost() << std::endl;
    }
  }
  void addNode(State<T>* node) {
    this->path.push_back(node);
  }
};

#endif //FLIGHTSIMULATORPART2__SOLUTION_H_
