
#include "Matrix.h"
#include <string>
#include <utility>
#include <iostream>

State<std::vector<int>>* Matrix::getInitialState() {
  return this->initialState;
}

bool Matrix::isGoalState(State<std::vector<int>>* curState) {
  return this->goalState->equals(curState);
}

std::vector<State<std::vector<int>>*> Matrix::getAllPossibleStates(State<std::vector<int>>* curState) {
  int row = curState->getState()->at(0);
  int column = curState->getState()->at(1);
  std::vector<State<std::vector<int>>*> neighbors;
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
    return (this->matrix[row][column]->getCost() !=  -1);
  }
  return false;
}

void Matrix::addCell(State<std::vector<int>> *state) {
  this->matrix[state->getState()->at(0)][state->getState()->at(1)] = state;
}
void Matrix::setGoalState(State<std::vector<int>>* state){
  this->goalState = state;
}
void Matrix::setInitialState(State<std::vector<int>>* state){
  this->initialState = state;
}


Matrix::Matrix(int testMat[5][5]) {
  std::string string;
  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 5; j++) {
      //string = "(" + std::to_string(i) + "," + std::to_string(j) + ")";
      std::vector<int> cell{i, j};
      State<std::vector<int>>* state = new State<std::vector<int>>(&cell, testMat[i][j]);
      this->addCell(state);
    }
  }
}

Matrix::Matrix(int size, State<std::vector<int>> *initial_state, State<std::vector<int>> *goal_state)
    : size(size), initialState(initial_state), goalState(goal_state) {
  this->matrix = std::vector<std::vector<State<std::vector<int>>*>>(size, std::vector<State<std::vector<int>>*>(size,nullptr));
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
