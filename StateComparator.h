#ifndef FLIGHTSIMULATORPART2__STATECOMPARATOR_H_
#define FLIGHTSIMULATORPART2__STATECOMPARATOR_H_

#include <vector>
#include "State.h"
template <typename T>
class StateComparator {
 public:
  bool operator() (State<T>* msg1, State<T>* msg2) const
  {
    return msg1->getState_Name().compare(msg2->getState_Name()) < 0;
  }
};

#endif //FLIGHTSIMULATORPART2__STATECOMPARATOR_H_
