#ifndef OBJECTADAPTER_H_
#define OBJECTADAPTER_H_

#include "Solver.h"
#include "Searchable.h"
#include "Searcher.h"
#include "Matrix.h"
#include "BFS.h"
#include <vector>

class ObjectAdapter : public Solver<Matrix*, std::string> {
 public:
  std::string solve(Matrix* problem) override;
};

#endif //OBJECTADAPTER_H_
