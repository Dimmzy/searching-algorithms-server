#ifndef COMPARE_H_
#define COMPARE_H_
#include "State.h"
template <typename T>
class Compare {
 public:
  bool operator() (State<T> *  state1, State<T>* state2) {
    return state1->getCostFromInitial() > state2->getCostFromInitial() ;
  }
  virtual ~Compare() = default;
};

#endif //FLIGHTSIMULATORPART2__COMPARE_H_
