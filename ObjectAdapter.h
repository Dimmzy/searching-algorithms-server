#ifndef OBJECTADAPTER_H_
#define OBJECTADAPTER_H_

#include "Solver.h"
#include "Searchable.h"
#include "Searcher.h"
#include "Matrix.h"
#include "Solution.h"
#include <vector>

/**
 * The ObjectAdapter handles passing our Searchable Objects onto a Searcher that solves the problem given.
 * It then receives the solution, adapts it into a string we can then send as a solution to the client handler, which
 * in turn sends it to the client.
 * @tparam T The Searchable Object template type.
 * @tparam S The State object template type.
 */
template <typename T>
class ObjectAdapter : public Solver<Matrix*, std::string> {
 public:
  explicit ObjectAdapter<T>(Searcher<T>* searcher) {
    this->searcher = searcher;
  }

  /**
   * Sends the searcher the problem, receives the solution and transforms it into a string we can then send and store
   * @param problem the Matrix we'll solve path finding for
   * @return the string representing the shortest path from the initial node to the goal node
   */
  std::string solve(Matrix *problem) override {
    Solution<T> *sol = this->searcher->search(problem);
    if (sol == nullptr) {
      return "Something went wrong!";
    }
    std::cout << "Num of nodes is " + std::to_string(sol->getNumofNodes()) << std::endl;
    std::cout << "Path length is " + std::to_string(sol->getPathLength()) << std::endl;
    sol->reversePath();
    std::string solution = sol->printSolution();
    return solution;
  }


 private:
  Searcher<T>* searcher; // The searcher we're going to use to find the shortest path
};

#endif //OBJECTADAPTER_H_