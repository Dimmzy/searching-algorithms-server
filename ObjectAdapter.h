#ifndef OBJECTADAPTER_H_
#define OBJECTADAPTER_H_

#include "Solver.h"
#include "Searcheable.h"
#include "Searcher.h"

template <typename T,typename P, typename S>
class ObjectAdapter : public Solver<P,S>{

 private:
Searcheable<T> searcheableItem;
Searcher<T> searcherItem;




};

#endif //OBJECTADAPTER_H_
