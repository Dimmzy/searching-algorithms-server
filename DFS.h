#ifndef DFS_H_
#define DFS_H_
#include <iostream>
#include "Solution.h"
#include "Searchable.h"
#include <stack>
#include <vector>
#include "Searcher.h"
#include <vector>
#include <algorithm>
#include "StateComparator.h"
#include <set>
template <typename T>
class DFS : public Searcher<T>{
 public:
  DFS<T>() {}

  virtual Solution<T>* search(Searchable<T>* searchableItem) {
    std::set<State<T> *, StateComparator<T>>* closed = new std::set<State<T> *, StateComparator<T>>();
    std::vector<State<T> *>* neighbors;
    std::stack<State<T> *> myStack;
    Solution<T>* solution = new Solution<T>();
    State<T>* initialState = searchableItem->getInitialState();
    State<T> *curState;
    typename std::vector<State<T> *>::iterator it;
    initialState->setCostFromInitial(initialState->getCost());
    myStack.push(initialState); //add root node to the stack
    // loop on the stack as long as it's not empty
    while(!myStack.empty()) {
      //get the node at the top of the stack
      curState = myStack.top();
      closed->emplace(curState);
      myStack.pop();

      if (searchableItem->isGoalState(curState)) {
        while (!curState->equals(initialState)) {
          solution->addNode(curState);
          curState = curState->getPreviousNode();
        }
        return solution;
        //solution->reversePath();
        //solution->printNodes();
      } else {
        neighbors = searchableItem->getAllPossibleStates(curState);
        for (State<T> *state : *neighbors) {
          if (closed->find(state) == closed->end()) {
            state->setPreviousNode(curState);
            state->setCostFromInitial(state->getCost() + curState->getCostFromInitial());
            //check if we found the destination
            if (searchableItem->isGoalState(curState)) {
              while (!curState->equals(initialState)) {
                solution->addNode(curState);
                curState = curState->getPreviousNode();
              }
              return solution;
              //solution->setInitialCost(initialState->getCost());
              //solution->reversePath();
              //solution->printNodes();
            } else {
              closed->emplace(curState);
              myStack.push(state);
            }
          }
        }
      }
    }

    if(myStack.empty()) {
      solution = NULL;
    }
    return solution;
  }

  virtual std::string getName() {
    return "DFS";
  }
};

#endif
