#ifndef DFS_H_
#define DFS_H_

#include "Solution.h"
#include "Searchable.h"
#include <stack>
#include <vector>
#include "Searcher.h"
template <typename T>
class DFS : public Searcher<T>{
 public:
  DFS() = default;

  virtual Solution<T>* search(Searchable<T>* searchableItem) {
    std::stack<State<T>> myStack;
    Solution<T>* solution = new Solution<T>();
    std::vector<State<T>> neighbors;
    State<T> initialState = searchableItem->getInitialState();
    initialState.setCostFromInitial(initialState.getCost());
    myStack.push(initialState); //add root node to the stack
    //need to check that the cost at the initial state is not -1 (infinity)
    State<T> curState;
    // loop on the stack as long as it's not empty
    while(!myStack.empty()) {
      //get the node at the top of the stack
      curState = myStack.top();
      curState.setCost(-1);
      myStack.pop();
      if (searchableItem->isGoalState(&curState)) {

        return solution->backTrace(&curState, &initialState);
      } else {
        neighbors = searchableItem->getAllPossibleStates(curState);
        for (typename std::vector<State<T>>::iterator it = neighbors.begin(); it < neighbors.end(); ++it) {
          (*it).setCostFromInitial((*it).getCost() + curState.getCostFromInitial());
          //check if we find the destination
          if (searchableItem->isGoalState(&curState)) {
            return solution->backTrace(&curState, &initialState);
          } else {
            myStack.push(*it);
          }
        }
      }
    }
    if(myStack.empty()) {

    }
  }

  virtual std::string getName() {
    return "DFS";
  }
};

#endif
