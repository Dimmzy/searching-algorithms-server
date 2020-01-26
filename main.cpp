#include "MySerialServer.h"
#include "Matrix.h"
#include "State.h"
#include "ObjectAdapter.h"
#include <vector>
#include "BFS.h"
#include "Searchable.h"

int main(int size, char *args[]) {
  //boot::Main::main(size, args);

  int myMat[5][5] = {{5,1,3,1,8}, {2,-1,1,1,7},{1,5,2,2,1},{8,-1,5,6,1},{3,1,4,6,5}};
  std::vector<int> cell1{0,0};
  std::vector<int> cell2{4,4};
  State<std::vector<int>>* initialState = new State<std::vector<int>>(&cell1, 5);
  State<std::vector<int>>* goalState = new State<std::vector<int>>(&cell2, 5);
  auto matrix = new Matrix(5,initialState,goalState);
  int rows = 5, columns = 5;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      std::vector<int>* cell = new std::vector<int>{i,j};
      matrix->addCell(new State<std::vector<int>>(cell,myMat[i][j]));
    }
  }
  matrix->printMatrix();
  auto bfs = new BFS<Matrix,std::vector<int>>();
  auto sol = bfs->search(matrix);
  sol->printNodes();
  //Searchable<std::vector<int>>* searchable = testMat;
  //DFS<std::vector<int>>* dfs = new ::DFS<std::vector<int>>();
  //Searcher<std::vector<int>>* searcher = ::new DFS<std::vector<int>>();
  /*
  ObjectAdapter<std::vector<int>>* object_adapter = new ObjectAdapter<std::vector<int>>(searcher);
  object_adapter->solve(searchable);
  */
  return 0;
}

