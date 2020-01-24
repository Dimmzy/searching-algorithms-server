
#include "Matrix.h"

#include <utility>

State<std::vector<int>> Matrix::getInitialState() {
  this->initialState->getState();
}

bool Matrix::isGoalState(State<std::vector<int>> curState) {
  return this->goalState->equals(curState);
}

std::vector<State<std::vector<int>>> Matrix::getAllPossibleStates(State<std::vector<int>> curState) {
  int row = curState.getState().at(0);
  int column = curState.getState().at(1);
  std::vector<State<std::vector<int>>> neighbors;
  /* TODO: Make a for loop (?) */
  if (validateCell(row+1,column))
    neighbors.push_back(this->matrix[row + 1][column]);
  if  (validateCell(row,column + 1))
    neighbors.push_back(this->matrix[row][column + 1]);
  if (validateCell(row-1,column))
    neighbors.push_back(this->matrix[row-1][column]);
  if (validateCell(row,column-1))
    neighbors.push_back(this->matrix[row][column-1]);
  return neighbors;
}

bool Matrix::validateCell(int row, int column) {
  if (row <= this->size && column <= this->size) {
    return (this->matrix[row][column].getCost() !=  -1);
  }
  return false;
}

void Matrix::addCell(State<std::vector<int>> *state) {
  this->matrix[state->getState().at(0),state->getState().at(1)] = state;
}

Matrix::Matrix(int size, State<std::vector<int>> *initial_state, State<std::vector<int>> *goal_state)
    : size(size), initialState(initial_state), goalState(goal_state) {}
