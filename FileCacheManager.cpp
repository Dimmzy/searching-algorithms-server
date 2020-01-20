#include <string>
#include <fstream>
#include <iostream>
#include "FileCacheManager.h"
#define SOL_FOLDER "Solutions/"

/**
 * @param problem given a problem string
 * @return return if we have a solution saved in cache
 */
bool FileCacheManager::findSolution(std::string problem) {
  return this->solutionCache.find(problem) != this->solutionCache.end();
}

/**
 * @param problem given a problem
 * @return read the solution file and return the solution string
 */
std::string FileCacheManager::getSolution(std::string problem) {
  std::ifstream solFile (this->solutionCache.at(problem));
  std::string solution;
  if(solFile.is_open()) {
    std::cout << "Getting Solution\n" << std::endl;
    getline(solFile,solution);
    solFile.close();
    return solution;
  } else
    std::cout << "Couldn't open file" << std::endl;
}

/**
 * A function that saves a passed solution from Client Handler
 * @param problem the problem string (which we use to classify the files prefix)
 * @param solution the solution we'll write into the file
 * @param fileName the type of solver used to solve it, the second part of the solverName
 */
void FileCacheManager::saveSolution(std::string problem,std::string solution, std::string fileName) {
  // Save solution to file
  std::ofstream solFile (SOL_FOLDER + fileName); // Gets a solverName from ClientHandler in the format of Problem.<SolverType>
  if (solFile.is_open()) {
    solFile << solution;
    solFile.close();
  } else
    std::cout << "Couldn't open file" << std::endl;
  // Add solution path to cache
  this->solutionCache.insert(std::pair<std::string,std::string>(problem, SOL_FOLDER + fileName));
}
FileCacheManager::FileCacheManager(std::string solverName) {

}
