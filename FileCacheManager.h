#ifndef SEARCHING_ALGORITHMS_SERVER__FILECACHEMANAGER_H_
#define SEARCHING_ALGORITHMS_SERVER__FILECACHEMANAGER_H_
#include "CacheManager.h"
#include <map>

class FileCacheManager : public CacheManager {
 private:
  std::map<std::string, std::string> solutionCache; // Key: Problem , Value: Filename (relative path)
 public:
  bool findSolution(std::string problem) override;
  std::string getSolution(std::string problem) override;
  void saveSolution(std::string problem, std::string solution, std::string filename) override;
};

#endif //SEARCHING_ALGORITHMS_SERVER__FILECACHEMANAGER_H_
