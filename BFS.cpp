
#include <algorithm>
#include "BFS.h"

template<typename T>
Solution<T> BFS<T>::search(Searchable<T>* searchableItem) {

  std::vector<State<T>> path;
  std::queue<State<T>> queue;
  State<T> init = searchableItem->getInitialState();
  queue.push(init);
  init.setVisited(true);
  while (!queue.empty()) {
    State<T> current = queue.front();
    queue.pop();
    if (searchableItem->isGoalState(current)) {
      while(current.getPreviousNode() != nullptr) {
        path.push_back(current);
        current = current.getPreviousNode();
      }
    } else {
      for (State<T> neighbor : searchableItem->getAllPossibleStates(current)) {
        if (!neighbor.checkVisited()) {
          queue.push(neighbor);
          neighbor.setVisited(true);
          neighbor.setCostFromInitial(neighbor.getCost() + current.getCost());
        }
      }
    }
  }
  searchableItem->reset();
  return new Solution<std::vector<int>>(path);
}
