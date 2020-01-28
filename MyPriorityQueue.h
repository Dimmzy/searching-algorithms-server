#ifndef MYPRIORITYQUEUE_H_
#define MYPRIORITYQUEUE_H_

#include <vector>
#include <functional>
#include <queue>
#include "State.h"
#include "Compare.h"
typedef State<std::vector<int>>* Val_TYPE;
typedef std::vector<Val_TYPE> Container_TYPE;
typedef std::priority_queue<Val_TYPE, Container_TYPE, Compare<std::vector<int>>> pri_queue;

class MyPriorityQueue : public std::priority_queue<Val_TYPE , Container_TYPE, Compare<std::vector<int>>>
{

 public:

  Container_TYPE::const_iterator find(const Val_TYPE val) const
  {
    auto first = this->c.cbegin();
    auto last = this->c.cend();
    while (first != last) {
      if ((*first)->equals(val)) return first;
      ++first;
    }
    return last;
  }
  void fixPlaceInPriorityQueue(Val_TYPE val) {
    auto it = find(val);
    if (this->c.end() != it) {
      this->c.erase(it);
    }
    this->push(val);
  }
  Container_TYPE::iterator begin(){
    return pri_queue::c.begin();
  }
  Container_TYPE::iterator end(){
    return pri_queue::c.end();
  }

  void erase(Val_TYPE val) {
    if(find(val) != this->c.cend()) {
      this->c.erase(find(val));
    }
  }


};

#endif //MYPRIORITYQUEUE_H_
