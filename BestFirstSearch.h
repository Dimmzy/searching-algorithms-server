#ifndef BESTFIRSTSEARCH_H_
#define BESTFIRSTSEARCH_H_
#include "Solution.h"
#include "Searchable.h"
#include "Searcher.h"
#include <queue>
#include <set>
#include "MyPriorityQueue.h"
#include <string>
#include "StateComparator.h"
template <typename T>
class BestFirstSearch : public Searcher<T> {
 private:
  MyPriorityQueue* my_priority_queue;
  int evaluatedNodes;

 public:
  BestFirstSearch() {
    this->my_priority_queue = new MyPriorityQueue();
    this->evaluatedNodes = 0;
  }

  ~BestFirstSearch() {
    //~this->my_priority_queue;
  }

  void addToOpenList(State<T>* curState) {
    this->my_priority_queue->push(curState);
  }

  State<T>* popOpenList() {
    this->evaluatedNodes++;
    State<T> * state = this->my_priority_queue->top();
    this->my_priority_queue->pop();
    return state;
  }

  unsigned long openListSize() {
    return this->my_priority_queue->size();
  }

  /*
  Best First Search:
    OPEN = [initial state] // a priority queue of states to be evaluated
    CLOSED = []
    // a set of states already evaluated
    while OPEN is not empty
      do
      1. n  dequeue(OPEN) // Remove the best node from OPEN
      2. add(n,CLOSED)
      // so we won’t check n again
      3. If n is the goal state,
        backtrace path to n (through recorded parents) and return path.
      4. Create n's successors.
      5. For each successor s do:
        a. If s is not in CLOSED and s is not in OPEN:
        update that we came to s from n
        add(s,OPEN)
        b. Otherwise, if this new path is better than previous one
          i. If it is not in OPEN add it to OPEN.
          ii. Otherwise, adjust its priority in OPEN done
   */
  Solution<T>* search(Searchable<T>* searchableItem) override {
    Solution<T>* solution = new Solution<T>();
    std::vector<State<T> *>* succerssors;
    State<T>* initialState = searchableItem->getInitialState();
    initialState->setCostFromInitial(initialState->getCost());
    addToOpenList(initialState);
    std::set<State<T> *, StateComparator<T>>* closed = new std::set<State<T> *, StateComparator<T>>();
    while (openListSize() > 0) {
      State<T>* n = popOpenList(); // removes the best state

      closed->emplace(n);
      if (n->equals(searchableItem->getGoalState())) {
        /* Backtrace and report to Solution Class */
        while(!n->equals(initialState)) {
          //std::cout << n->getState_Name() << std::endl;
          solution->addNode(n);
          n = n->getPreviousNode();
        }
        //solution->setInitialCost(initialState->getCost());
        //solution->printNodes();
        //solution->reversePath();
        return solution;
      }
      // calling the delegated method, returns a vector of states with n as a parent
      succerssors = searchableItem->getAllPossibleStates(n);

      for(State<T>* state : *succerssors) {
        //std::cout << state->getState_Name() << std::endl;
        if(closed->find(state) == closed->end() && this->my_priority_queue->find(state) ==
            this->my_priority_queue->end())
        {
          state->setPreviousNode(n);
          state->setCostFromInitial(state->getCost() + n->getCostFromInitial());
          addToOpenList(state);
        } else {
          if(n->getCostFromInitial() + state->getCost() < state->getCostFromInitial()) {
            if(this->my_priority_queue->find(state) != this->my_priority_queue->end()) {
              addToOpenList(state);
            } else {
              this->my_priority_queue->fixPlaceInPriorityQueue(state);
            }
          }
        }
      }
    }
  }
  virtual std::string getName() {
    return "BestFirstSearch";
  }
};

#endif //BESTFIRSTSEARCH_H_
