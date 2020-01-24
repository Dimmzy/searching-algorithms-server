#include "ObjectAdapter.h"

template<typename T, typename P, typename S>
S ObjectAdapter<T, P, S>::solve(P problem) {
  return nullptr;
}

template<typename T, typename P, typename S>
std::string ObjectAdapter<T, P, S>::getName() {
  return this->searcher.getName();
}
