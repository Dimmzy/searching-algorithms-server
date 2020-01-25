#include "MySerialServer.h"
#include "Matrix.h"
#include "State.h"
#include "ObjectAdapter.h"
#include "DFS.h"
#include <vector>
#include "DFS.cpp"
int main(int size, char *args[]) {
  //boot::Main::main(size, args);

  int myMat[5][5] = {{5,1,3,1,8}, {2,-1,1,1,7},{1,5,2,2,1},{8,-1,5,6,1},{3,1,4,6,5}};
  Matrix* testMat = new Matrix(myMat);

  std::vector<int> cell1{0,0};
  std::vector<int> cell2{4,4};
  State<std::vector<int>>* initialState = new State<std::vector<int>>(&cell1, 5);
  State<std::vector<int>>* goalState = new State<std::vector<int>>(&cell2, 5);

  testMat->setGoalState(goalState);
  testMat->setInitialState(initialState);

  Searchable<std::vector<int>>* searchable = testMat;
  DFS<std::vector<int>>* dfs = new ::DFS<std::vector<int>>();
  //Searcher<std::vector<int>>* searcher = ::new DFS<std::vector<int>>();
  /*
  ObjectAdapter<std::vector<int>>* object_adapter = new ObjectAdapter<std::vector<int>>(searcher);
  object_adapter->solve(searchable);
  */
  return 0;
}

