#ifndef MATRIX_H_
#define MATRIX_H_

#include "Searchable.h"
#include <vector>

/**
 * The Matrix class is a class implementing a Searchable object.
 * It allows us to have a defined structure to handle complex objects such as matrix and have functionality that will
 * assist us in solving problems relating to the matricies.
 */
class Matrix : public Searchable<std::vector<int>> {
 public:
  Matrix(int size, State<std::vector<int>> *initial_state, State<std::vector<int>> *goal_state);
  void addCell(State<std::vector<int>> *state);
  State<std::vector<int>>* getInitialState() override;
  State<std::vector<int>>* getGoalState() override;
  bool isGoalState(State<std::vector<int>>* curState) override;
  std::vector<State<std::vector<int>>*>* getAllPossibleStates(State<std::vector<int>>* curState) override;
 private:
  int size;
  State<std::vector<int>>* initialState;
  State<std::vector<int>>* goalState;
  std::vector<std::vector<State<std::vector<int>>*>> matrix;
  bool validateCell(int row, int column);
};

#endif //MATRIX_H_
