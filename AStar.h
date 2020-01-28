#ifndef FLIGHTSIMULATORPART2__ASTAR_H_
#define FLIGHTSIMULATORPART2__ASTAR_H_

#include "Searcher.h"
#include <vector>
#include <queue>

/**
 * AStar is a Path Finding algorithm that attempts to find the best (over close-to best) path with minimal cost from
 * the starting node to the goal node.
 * We'll implement the Searcher template to handle it.
 * @tparam T The Searchable object we'll find the path of
 * @tparam S The State object that denotes a state in our searchable object.
 */
template<typename T, typename S>
class AStar : public Searcher<T, S> {
 public:
  Solution<S> *search(T *searchableItem) override {
    /* Initialize Open and Closed list */
    int numOfNodes = 0;
    std::vector<State<S> *> openList;
    State<S> *initial = searchableItem->getInitialState();
    initial->setFScore(0); // Initial's fScore is always zero.
    openList.push_back(initial);
    initial->setCostFromInitial(0);
    while (!openList.empty()) {
      int minIndex = getMinIndex(openList); // Gets the index of the node with the minimal fScore in the OpenList
      State<S> *minNode = openList.at(minIndex);
      if (searchableItem->isGoalState(minNode)) {
        /* Backtrace and report to Solution Class */
        auto* solution = new Solution<S>();
        double sum = 0;
        while(minNode != initial) {
          solution->addNode(minNode);
          minNode = minNode->getPreviousNode();
        }
        solution->setInitialCost(initial->getCost());
        return solution;
      }
      openList.erase(openList.begin()+minIndex);
      for (State<S> *neighbor : *searchableItem->getAllPossibleStates(minNode)) { // For each of the neighbors of minNode
        double tentativeG = neighbor->getCost() + minNode->getCostFromInitial(); // Tentative minCost path
        if (tentativeG < neighbor->getCostFromInitial()) { // If the path we found is cheaper, we'll save it
          neighbor->setPreviousNode(minNode);
          neighbor->setCostFromInitial(tentativeG);
          neighbor->setFScore(tentativeG + manhattanDistance(neighbor,searchableItem->getGoalState()));
          if(std::find(openList.begin(),openList.end(),neighbor) == openList.end()) {
            openList.push_back(neighbor);
          }
        }
      }
    }
  }

  /**
   * Gets the node with the smallest f Value  in the openList
   * @param openList the list we'll extract from
   * @return the index of the minimal node
   */
  int getMinIndex(std::vector<State<S> *> openList) {
    double minScore = std::numeric_limits<double>::infinity();
    int i = -1; // Starts at -1 since we increment by 1 for each node from the zero index
    int minIndex = 0;
    for (State<S> *node : openList) {
      i++;
      if (node->getFScore() < minScore) {
        minScore = node->getFScore();
        minIndex = i;
      }
    }
    return minIndex;
  }

  /**
   * Manhattan Distance Heuristic function used with the A* Algorithm. Used as an heuristic for the A Star algorithm/
   * @param current Current cell
   * @param goal Goal cell
   * @return the sum of the absolute values of the differences in the goal and current x and y coordinates.
   */
  int manhattanDistance(State<S> *current, State<S> *goal) {
    return abs(current->getX() - goal->getX()) + abs(current->getY() - goal->getY());
  }
};

#endif //FLIGHTSIMULATORPART2__ASTAR_H_
