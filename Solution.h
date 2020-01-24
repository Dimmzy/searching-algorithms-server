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
  /*
  Solution<T> () {
    //this->listOfNodes = new std::vector<State<T>>();
  }
  ~Solution() {
    //~this->listOfNodes;
  }
   */
  void addNode(State<T>& curState) {
    this->listOfNodes.emplace_back(curState);
  }
  void reverse() {
    this->listOfNodes.reserve(this->listOfNodes.begin(), this->listOfNodes.end());
  }

  Solution<T> backTrace(State<T>& finalNode, State<T>& startNode) {
    while(!finalNode.equals(startNode)) {
      this->addNode(finalNode);
      finalNode = finalNode.getPreviousNode();
    }
    this->addNode(startNode);
    this->reverse();
    return this;
  }
};

#endif //FLIGHTSIMULATORPART2__SOLUTION_H_
