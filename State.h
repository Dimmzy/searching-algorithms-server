#ifndef STATE_H_
#define STATE_H_

#include <string>

/**
 * The State Object is a specific state in a Searchable object that we use to
 * @tparam T How we define our state to be (ex. in the Matrix Searchable, it would be an int tuple denoting indices)
 */
template<typename T>
class State {
 private:
  T *state; // The state itself
  std::string state_name; // The name of the current state in a string type
  double fScore; // the F score is the score function used to define the cost of the node in the A* algorithm
  double cost; // the cost to cross this state
  State<T> *cameFrom; // the state we came from to this state
  double costFromInitial; //cost to reach this state from the initial state

 public:
  State<T>(T *state, double cost) {
    this->state = state;
    this->state_name = "(" + std::to_string(state->at(0)) + "," + std::to_string(state->at(1)) + ")";
    this->cost = cost;
    this->cameFrom = nullptr;
    this->costFromInitial = 99999; // TODO: Change to "infinity"
  }

  /*
   * Gets the X coordinate of the state (when state is an int vector)
   */
  int getX() {
    return this->state->at(1);
  }

  /*
   * Gets the Y coordinate of the state (when state is an int vector)
   */
  int getY() {
    return this->state->at(0);
  }

  /**
   * Sets the F score of the node (used in A* Algorithm)
   * @param score the score to set to.
   */
  void setFScore(double score) {
    this->fScore = score;
  }

  /**
   * @return returns the nodes FScore.
   */
  double getFScore() {
    return this->fScore;
  }

  /**
   * Comparison function for two states, compares by unique name
   * @param otherState the state we compare to
   * @return whether the states are equal
   */
  bool equals(State<T> *otherState) {
    return this->state_name.compare(otherState->getState_Name()) == 0;
  }

  /**
   * Sets the cost of traversing from the initial node to this one
   * @param cost the cost we set to.
   */
  void setCostFromInitial(const double cost) {
    this->costFromInitial = cost;
  }

  /**
   * @return returns the cost to traverse through this node from the initial node.
   */
  double getCostFromInitial() {
    return this->costFromInitial;
  }

  /**
   * @return returns the object defining the state.
   */
  T *getState() {
    return this->state;
  }

  /**
   * @return returns the name defining the state
   */
  std::string getState_Name() {
    return this->state_name;
  }

  /**
   * @return returns the cost of the current state
   */
  double getCost() {
    return this->cost;
  }

  /**
   * @param cost sets the cost of the current state
   */
  void setCost(double cost) {
    this->cost = cost;
  }

  /**
   * @return Returns the node previous to this one in a certain path through the searchable object
   */
  State<T> *getPreviousNode() {
    return this->cameFrom;
  }

  /**
   * @param previousNode sets the previous node to this one in a certain path through the searchable object
   */
  void setPreviousNode(State<T> *previousNode) {
    this->cameFrom = previousNode;
  }

  bool operator==(State<T>* state) {
    return this->getState_Name().compare(state->getState_Name()) == 0;
  }
};

#endif //STATE_H_
