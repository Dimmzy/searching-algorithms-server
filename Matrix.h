
#ifndef MATRIX_H_
#define MATRIX_H_
#include "Searchable.h"
#include <vector>

class Matrix : public Searchable<std::vector<int>> {
 public:
  Matrix(int size, State<std::vector<int>> *initial_state, State<std::vector<int>> *goal_state);
  void addCell(State<std::vector<int>> *state);
  State<std::vector<int>>* getInitialState() override;
  bool isGoalState(State<std::vector<int>>* curState) override;
  std::vector<State<std::vector<int>>*>* getAllPossibleStates(State<std::vector<int>>* curState) override;
  void printMatrix();
 private:
  int size;
  State<std::vector<int>>* initialState;
  State<std::vector<int>>* goalState;
  std::vector<std::vector<State<std::vector<int>>*>> matrix;
  bool validateCell(int row, int column);
};

#endif //MATRIX_H_
