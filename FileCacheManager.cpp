//
// Created by dima on 1/16/20.
//

#include <string>
#include <fstream>
#include <iostream>
#include "FileCacheManager.h"


bool FileCacheManager::findSolution(std::string problem) {
  return this->solutionCache.find(problem) != this->solutionCache.end();
}
std::string FileCacheManager::getSolution(std::string problem) {
  std::ifstream solFile (this->solutionCache.at(problem));
  std::string solution;
  if(solFile.is_open()) {
    std::cout << solution;
    solFile.close();
  } else
    std::cout << "Couldn't open file" << std::endl;
}
void FileCacheManager::saveSolution(std::string problem, std::string solution) {
  std::ofstream solFile (problem + "S");
  if (solFile.is_open()) {
    solFile << solution;
    solFile.close();
  } else
    std::cout << "Couldn't open file" << std::endl;
}
