#ifndef STATE_H_
#define STATE_H_
#include "string"
template<typename T>
class State {
 private:
  T* state;
  std::string state_name; // the state_name represented by a string
  double cost; // the cost to cross this state_name
  State<T>* cameFrom; // the state_name we came from to this state_name (setter)
  double costFromInitial; //cost to reach this state_name (set by a setter)
  bool visited;

 public:
  State<T> () = default;
  State<T>(std::string &state, double cost) {
    this->state_name = state;
    this->cost = cost;
    this->cameFrom = nullptr;
    this->costFromInitial = 0;
    visited = false;
  }

  State<T>(T* state, double cost) {
    this->state = state;
    this->cost = cost;
    this->cameFrom = nullptr;
    this->costFromInitial = 0;
    visited = false;
  }

  bool equals(State<T>* otherState) {
    return this->state_name.compare(otherState->getState_Name()) == 0;
  }
  void setVisited(bool v) {
    this->visited = v;
  }

  bool checkVisited() {
    return this->visited;
  }

  void setCostFromInitial(const double cost) {
    this->costFromInitial = cost;
  }
  double getCostFromInitial() {
    return this->costFromInitial;
  }

  T* getState() {
    return this->state;
  }

  std::string getState_Name() {
    return this->state_name;
  }
  double getCost() {
    return this->cost;
  }
  void setCost(double cost) {
    this->cost = cost;
  }
  State<T> *getPreviousNode() {
    return this->cameFrom;
  }
  void setPreviousNode(State<T> *previousNode) {
    this->cameFrom = previousNode;
  }
};

#endif //STATE_H_
