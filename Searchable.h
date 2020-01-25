#ifndef SEARCHEABLE_H_
#define SEARCHEABLE_H_
#include <vector>
#include "State.h"

template<typename T>
class Searchable {
 public:
  virtual State<T>* getInitialState() = 0;
  virtual bool isGoalState(State<T>* curState) = 0;
  virtual std::vector<State<T>*> getAllPossibleStates(State<T>* curState) = 0;
};

#endif //SEARCHEABLE_H_
