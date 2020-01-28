#ifndef SEARCHEABLE_H_
#define SEARCHEABLE_H_

#include <vector>
#include "State.h"

/**
 * The Searchable interface defines an object that we can search through to find things like optimal paths.
 * @tparam T The State that defines a specific state in our object (for example, in Matrices, it's a specific cell).
 */
template<typename T>
class Searchable {
 public:
  virtual State<T>* getInitialState() = 0;
  virtual State<T>* getGoalState() = 0;
  virtual bool isGoalState(State<T>* curState) = 0;
  virtual std::vector<State<T>*>* getAllPossibleStates(State<T>* curState) = 0;
};

#endif //SEARCHEABLE_H_
