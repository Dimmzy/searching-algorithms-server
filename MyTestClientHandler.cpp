#include "MyTestClientHandler.h"
#define BUFFERSIZE 1024
/**
 * A function that handles the clients. Inputs the problem and output the result.
 * @param input_stream Client Socket
 * @param output_stream Client Socket
 */
void MyTestClientHandler::handleClient(int input_stream, int output_stream) {
  char bufferProblem[BUFFERSIZE] = {0}, bufferSolution[BUFFERSIZE] = {0};
  std::string problem, solution, fileName;


  read(input_stream, bufferProblem, BUFFERSIZE);

  problem = bufferProblem;
  //remove '\n', '\r' characters
  problem.erase(std::remove(problem.begin(), problem.end(), '\n'), problem.end());
  problem.erase(std::remove(problem.begin(), problem.end(), '\r'), problem.end());
  //The connection with the client will stop as the client types "end"
  while(problem != "end")
  {
    fileName = problem + '.' + "StringReverser";
    //first check if we have already solved this problem before
    if (this->cManager->findSolution(problem)) {
      std::cout << "Found Solution for " + fileName << std::endl;
      solution = this->cManager->getSolution(problem) + '\n';
    } else { //it is a brand new problem
      solution = this->solver->solve(problem) + '\n';
      this->cManager->saveSolution(problem, solution);
    }
    //clean the buffer of the solution
    bzero(bufferSolution, BUFFERSIZE);
    strcpy(bufferSolution, solution.c_str());
    //send back to client the result of his problem
    send(output_stream, bufferSolution, BUFFERSIZE, 0);
    //clean the buffer of the problem
    bzero(bufferProblem, BUFFERSIZE);
    //input new problem to solve or "end"-to stop the connection with the server
    read(input_stream, bufferProblem, BUFFERSIZE);
    problem = bufferProblem;
    //remove '\n', '\r' characters
    problem.erase(std::remove(problem.begin(), problem.end(), '\n'), problem.end());
    problem.erase(std::remove(problem.begin(), problem.end(), '\r'), problem.end());
  }
  //after we finish the connection with the server close the client socket
  close(input_stream);
}
/**
 * Constructor
 * @param string_reverser The responsible object for solving the recieved problems from the client
 * @param cacheManager The database in which we keep all the problems we have already solved
 */
MyTestClientHandler::MyTestClientHandler(Solver<std::string, std::string> *string_reverser, CacheManager *
cacheManager) {
  this->solver = string_reverser;
  this->cManager = cacheManager;
}