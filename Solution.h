//
// Created by haim on 20/01/2020.
//

#ifndef FLIGHTSIMULATORPART2__SOLUTION_H_
#define FLIGHTSIMULATORPART2__SOLUTION_H_
#include <vector>
#include "State.h"
template <typename T>
class Solution {
 private:
  std::vector<State<T>> listOfNodes;
 public:
  void addNode(State<T> curState) {
    this->listOfNodes.emplace_back(curState);
  }

};

#endif //FLIGHTSIMULATORPART2__SOLUTION_H_
