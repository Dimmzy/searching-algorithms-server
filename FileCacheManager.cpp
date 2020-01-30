#include <string>
#include <fstream>
#include <iostream>
#include <dirent.h>
#include <vector>
#include "FileCacheManager.h"

#define SOL_FOLDER "Solutions/"

/**
 * @param problem given a problem string
 * @return return if we have a solution saved in cache
 */
bool FileCacheManager::findSolution(std::string problem) {
  return this->solutionCache->find(problem) != this->solutionCache->end();
}

/**
 * Checks the Solutions folder in the relative path and loads any solutions to our cache so we can reuse them
 */
void FileCacheManager::loadToCache() {
  std::vector<std::string> solList;
  DIR *solDirectory;
  struct dirent *ent;
  /* Opens the directory, reading each file inside it and appending it to our solutions list */
  if ((solDirectory = opendir("Solutions")) != nullptr) {
    while ((ent = readdir(solDirectory)) != nullptr)
      solList.emplace_back(ent->d_name);
    closedir(solDirectory);
  }
  // For each solution in the string vector, add it to our existing solutions cache for faster retrieval.
  for (const auto &solution : solList) {
    this->solutionCache->insert(std::pair<std::string, std::string>(solution, SOL_FOLDER + solution));
  }
}

/**
 * @param problem given a problem
 * @return read the solution file and return the solution string
 */
std::string FileCacheManager::getSolution(std::string problem) {
  std::ifstream solFile(this->solutionCache->at(problem));
  std::string solution;
  if (solFile.is_open()) {
    std::cout << "Getting Solution\n" << std::endl;
    getline(solFile, solution);
    solFile.close();
    return solution;
  } else {
    return "Couldn't open file";
  }

}

/**
 * A function that saves a passed solution from Client Handler
 * @param problem the problem string (which we use to classify the files prefix)
 * @param solution the solution we'll write into the file
 * @param fileName the type of solver used to solve it, the second part of the solverName
 */
void FileCacheManager::saveSolution(std::string problem, std::string solution) {
  // Save solution to file
  std::ofstream
      solFile(SOL_FOLDER + problem); // Gets a solverName from ClientHandler in the format of Problem.<SolverType>
  if (solFile.is_open()) {
    solFile << solution;
    solFile.close();
  } else
    std::cout << "Couldn't open file" << std::endl;
  // Add solution path to cache
  this->solutionCache->insert(std::pair<std::string, std::string>(problem, SOL_FOLDER + problem));
}
