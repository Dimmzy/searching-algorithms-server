
#include "Matrix.h"
#include <string>
#include <iostream>

State<std::vector<int>> *Matrix::getInitialState() {
  return this->initialState;
}

State<std::vector<int>>* Matrix::getGoalState() {
  return this->goalState;
}

bool Matrix::isGoalState(State<std::vector<int>> *curState) {
  return this->goalState->equals(curState);
}

std::vector<State<std::vector<int>> *>* Matrix::getAllPossibleStates(State<std::vector<int>> *curState) {
  int row = curState->getState()->at(0);
  int column = curState->getState()->at(1);
  auto neighbors = new std::vector<State<std::vector<int>>*>;
  /* TODO: Make a for loop (?) */
  if (validateCell(row + 1, column))
    neighbors->push_back(this->matrix[row + 1][column]);
  if (validateCell(row, column + 1))
    neighbors->push_back(this->matrix[row][column + 1]);
  if (validateCell(row - 1, column))
    neighbors->push_back(this->matrix[row - 1][column]);
  if (validateCell(row, column - 1))
    neighbors->push_back(this->matrix[row][column - 1]);
  return neighbors;
}

bool Matrix::validateCell(int row, int column) {
  if (row < this->size && column < this->size && row >= 0 && column >= 0) {
    return (this->matrix[row][column]->getCost() != -1);
  }
  return false;
}

void Matrix::addCell(State<std::vector<int>> *state) {
  this->matrix[state->getState()->at(0)][state->getState()->at(1)] = state;
}

Matrix::Matrix(int size, State<std::vector<int>> *initial_state, State<std::vector<int>> *goal_state)
    : size(size), initialState(initial_state), goalState(goal_state) {
  this->matrix =
      std::vector<std::vector<State<std::vector<int>> *>>(size, std::vector<State<std::vector<int>> *>(size, nullptr));
}

void Matrix::printMatrix() {
  for (int i = 0; i < this->size; i++) {
    for (int j = 0; j < this->size; j++) {
      std::cout << this->matrix[i][j]->getState()->at(0);
      std::cout << this->matrix[i][j]->getState()->at(1);
      std::cout << "(";
      std::cout << this->matrix[i][j]->getCost();
      std::cout << ")";
      std::cout << " ";
    }
    std::cout << std::endl;
  }
}
