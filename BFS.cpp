
#include <algorithm>
#include "BFS.h"

template<typename T>
Solution<T> BFS<T>::search(Searchable<T>* searchableItem) {

  std::vector<State<T>> path;
  std::queue<State<T>> queue;
  std::vector<State<T>> visited;
  State<T> init = searchableItem.getInitialState();
  visited.push_back(init);
  queue.push(init);
  while (!queue.empty()) {
    State<T> current = queue.front();
    queue.pop();
    if (searchableItem.isGoalState(current)) {
      while(current.getPreviousNode() != nullptr) {
        path.push_back(current);
        current = current.getPreviousNode();
      }
    } else {
      for (State<T> neighbor : searchableItem.getAllPossibleStates(current)) {
        if (std::find(visited.begin(),visited.end(),current) != visited.end()) {
          queue.push(neighbor);
          visited.push_back(neighbor);
        }
      }
    }
  }
  return new Solution<std::vector<int>>(path);
}
