//
// Created by haim on 14/01/2020.
//

#include "MyTestClientHandler.h"

void MyTestClientHandler::handleClient(std::istream input_stream, std::ostream output_stream) {
  char bufferProblem[1024] = {0}, bufferSolution[1024] = {0};
  std::string problem;
  this->solver
  while(input_stream.getline(bufferProblem, sizeof(bufferProblem) / sizeof(char))) {
    problem = bufferProblem;
    if(this->cache_manager.findSolution(problem)) {
      bufferSolution = this->cache_manager.getSolution(problem);
    } else {
        bufferSolution = this->solver.solve(problem);
        
    }
    output_stream.write(bufferSolution, sizeof(bufferSolution) / sizeof(char));
  }
}
