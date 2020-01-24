#ifndef BESTFIRSTSEARCH_H_
#define BESTFIRSTSEARCH_H_
#include <list>
#include "Solution.h"
#include "Searchable.h"
#include "Searcher.h"
#include <queue>
#include <unordered_set>
class unordered_set;
template <typename T>
class BestFirstSearch : public Searcher<T> {
 private:
  std::priority_queue<State<T>> my_priority_queue;
  int evaluatedNodes;

 public:
  BestFirstSearch() {
    this->my_priority_queue = new std::priority_queue<State<T>>();
    this->evaluatedNodes = 0;
  }

  ~BestFirstSearch() {
    ~this->my_priority_queue;
  }

  void addToOpenList(State<T>& curState) {
    this->my_priority_queue.push(curState);
  }

  State<T> popOpenList() {
    this->evaluatedNodes++;
    return this->my_priority_queue.top();
  }

  unsigned long openListSize() {
    return this->my_priority_queue.size();
  }

  void fixPlaceInPriorityQueue(State<T>& state) {
    typename std::priority_queue<State<T>>::iterator it = findStateInPriorityQueue(state);
    if(it != this->my_priority_queue.c.end()) {
      this->my_priority_queue.c.erase(it);
    }
    this->my_priority_queue.push(state);
  }

  typename std::priority_queue<State<T>>::iterator findStateInPriorityQueue(const State<T>& curState) {
    std::priority_queue<State<T>> temp;
    typename std::priority_queue<State<T>>::iterator start =  this->my_priority_queue.c.begin();
    typename std::priority_queue<State<T>>::iterator end = this->my_priority_queue.c.end();
    typename std::priority_queue<State<T>>::iterator it = start;
    while(it != end) {
      if(curState.equals((*it))) {
        return it;
      }
    }
    return it;
  }

  Solution<T>* search(Searchable<T>* searchableItem) override {
    std::list<State<T>> succerssors;
    State<T> initialState = searchableItem->getInitialState();
    initialState.setCostFromInitial(initialState.getCost());
    addToOpenList(initialState);
    std::unordered_set<State<T>> closed = new std::unordered_set<State<T>>();
    while (openListSize() > 0) {
      State<T> n = popOpenList(); // removes the best state

      closed.emplace(n);
      if (n.equals(searchableItem->getIGoallState())) {
        Solution<T>* solution = new Solution<T>();
        return solution->backTrace(&n, &initialState); // back traces through the parents
      }
      // calling the delegated method, returns a list of states with n as a parent
      succerssors = searchableItem->getAllPossibleStates(n);
      for(State<T> state : succerssors) {
        if(closed.find(state) != closed.end() && findStateInPriorityQueue(state) != this->my_priority_queue.c.end()) {
          state.setCostFromInitial(state.getCost() + n.getCost());
          addToOpenList(state);
        } else {
          if(n.getCostFromInitial() + state.getCost() < state.getCostFromInitial()) {
            if(findStateInPriorityQueue(state) != this->my_priority_queue.c.end()) {
              addToOpenList(state);
            } else {
              fixPlaceInPriorityQueue(state);
            }
          }
        }
      }
    }
  }
};

#endif //BESTFIRSTSEARCH_H_
