#ifndef STATE_H_
#define STATE_H_
#include "string"
template <typename T>
class State {
 private:
  std::string state; // the state represented by a string
  double cost; // cost to reach this state (set by a setter)
  State<T>* cameFrom; // the state we came from to this state (setter)

 public:
  State<T>(std::string state, double cost) {
    this->state = state;
    this->cost = cost;
  }
  bool equals(State<T> otherState) {
    return this->state.compare(otherState.getState() == 0;
  }

  std::string getState() {
    return this->state;
  }
  double getCost() {
    return this->cost;
  }
  State<T>* getPreviousNode() {
    return this->cameFrom;
  }
  void setPreviousNode(State<T> *previousNode) {
    this->cameFrom - previousNode;
  }
};

#endif //STATE_H_
