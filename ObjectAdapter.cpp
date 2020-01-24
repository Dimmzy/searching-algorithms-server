#include "ObjectAdapter.h"

std::string ObjectAdapter::solve(Matrix* problem) {
  Searcher<std::vector<int>>* BFS = new ::BFS<std::vector<int>>();
  Solution<std::vector<int>> sol = BFS->search(problem);
}
