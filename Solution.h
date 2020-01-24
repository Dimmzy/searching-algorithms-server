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
  Solution<T> (std::vector<State<T>> sol) {
    this->listOfNodes = sol;
  }
  std::vector<State<T>> getSolution() {
    return reverse(this->listofNodes);
  }
};
#endif //FLIGHTSIMULATORPART2__SOLUTION_H_
