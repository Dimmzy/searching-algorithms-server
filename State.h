#ifndef STATE_H_
#define STATE_H_
#include "string"
template <typename T>
class State {
 private:
  std::string state; // the state represented by a string
  double cost; // the cost to cross this state
  State<T>* cameFrom; // the state we came from to this state (setter)
  double costFromInitial; //cost to reach this state (set by a setter)

 public:
  State<T>(std::string& state, double cost) {
    this->state = state;
    this->cost = cost;
    this->cameFrom= nullptr;
    this->costFromInitial = 0;
  }
  bool equals(State<T>& otherState) {
    return this->state.compare(otherState.getState()) == 0;
  }

  void setCostFromInitial(const double cost) {
    this->costFromInitial = cost;
  }
  double getCostFromInitial() {
    return this->costFromInitial;
  }

  std::string getState() {
    return this->state;
  }
  double getCost() {
    return this->cost;
  }
  void setCost(double cost) {
    this->cost = cost;
  }
  State<T>* getPreviousNode() {
    return this->cameFrom;
  }
  void setPreviousNode(State<T> *previousNode) {
    this->cameFrom - previousNode;
  }
};

#endif //STATE_H_
