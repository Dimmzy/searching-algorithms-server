#include "Matrix.h"
#include <string>
#include <iostream>

/**
 * @return returns the initial state of the matrix, aka. the starting cell.
 */
State<std::vector<int>> *Matrix::getInitialState() {
  return this->initialState;
}

/**
 * @return returns the goal state of the matrix, aka. the ending cell.
 */
State<std::vector<int>>* Matrix::getGoalState() {
  return this->goalState;
}

/**
 * Checks whether the passed on state(cell) is the goal state.
 * @param curState the state we check
 * @return whether it's the goal state.
 */
bool Matrix::isGoalState(State<std::vector<int>> *curState) {
  return this->goalState->equals(curState);
}

/**
 * Returns all the neighbors of the cell (UP,DOWN,LEFT,RIGHT) if they exist inside of a State vector.
 * @param curState the state we get the neighbors of
 * @return a vector consisting of all valid (cost isn't -1 or out of bounds) neighbors.
 */
std::vector<State<std::vector<int>> *>* Matrix::getAllPossibleStates(State<std::vector<int>> *curState) {
  /* Gets current row and column of our state */
  int row = curState->getState()->at(0);
  int column = curState->getState()->at(1);
  auto neighbors = new std::vector<State<std::vector<int>>*>;
  /* Checks if cell is valid, if it is, add it to the vector */
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

/*
 * Validates the cells by checking indices in regards to matrix size, and that their cost is applicable.
 */
bool Matrix::validateCell(int row, int column) {
  if (row < this->size && column < this->size && row >= 0 && column >= 0) {
    return (this->matrix[row][column]->getCost() != -1);
  }
  return false;
}

/**
 * Adds a state(cell) into the matrix, we insert it into the [x][y] indices according to the state.
 * @param state the state we'll insert
 */
void Matrix::addCell(State<std::vector<int>> *state) {
  this->matrix[state->getState()->at(0)][state->getState()->at(1)] = state;
}

/**
 * Matrix Object constructor.
 * @param matrixSize Size of the matrix
 * @param initial_state The starting cell
 * @param goal_state The last cell
 */
Matrix::Matrix(int matrixSize, State<std::vector<int>> *initial_state, State<std::vector<int>> *goal_state)
    : size(matrixSize), initialState(initial_state), goalState(goal_state) {
  this->matrix =
      std::vector<std::vector<State<std::vector<int>> *>>(matrixSize,
                                                          std::vector<State<std::vector<int>> *>(matrixSize, nullptr));
}

void Matrix::printMatrix() {
  for(int i = 0; i < this->size; i++) {
    for(int j = 0; j < this->size; j++) {
      std::cout << this->matrix[i][j]->getCost();
      std::cout << " ";
    }
    std::cout << std::endl;
  }
  std::cout << "FUCK 2D ARRAYS\n";
}

