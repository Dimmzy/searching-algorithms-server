//
// Created by haim on 14/01/2020.
//

#include <unistd.h>
#include <sys/socket.h>
#include "MyTestClientHandler.h"

void MyTestClientHandler::handleClient(int input_stream, int output_stream) {
  char bufferProblem[1024] = {0}, bufferSolution[1024] = {0};
  std::string problem, solution, fileName;

  int read1 = recv(input_stream, bufferProblem, 1024, 0);
  while(true)
  {
    problem = bufferProblem;
    if(this->cache_manager->findSolution(problem)) {
      solution = this->cache_manager->getSolution(problem);
    } else {
      solution = this->solver->solve(problem);
      fileName = problem + "." + typeid(solver).name();
      this->cache_manager->saveSolution(problem, solution, fileName);
    }
    strcpy(bufferSolution, solution.c_str());
    send(output_stream, bufferSolution, sizeof(bufferSolution) / sizeof(char), 0);
  }
}
MyTestClientHandler::MyTestClientHandler(Solver<std::string , std::string>* string_reverser, CacheManager*
cache_manager) {
  this->solver = string_reverser;
  this->cache_manager = cache_manager;
}