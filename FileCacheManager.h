#ifndef SEARCHING_ALGORITHMS_SERVER__FILECACHEMANAGER_H_
#define SEARCHING_ALGORITHMS_SERVER__FILECACHEMANAGER_H_

#include "CacheManager.h"
#include <map>

/**
 * The File Cache Manager allows us to save and load solutions into files and a cache.
 * In terms of files, a solution filename will be the hash of the string of the problem.
 * In terms of the cache, we'll load into cache the files solution between iterations of the program to improve
 * performance.
 */
class FileCacheManager : public CacheManager {
 private:
  std::map<std::string, std::string> *solutionCache; // Key: Problem ,  Value: Filename (relative path)
 public:
  explicit FileCacheManager(std::map<std::string, std::string> *solutionCache) {
    this->solutionCache = solutionCache;
  }
  void loadToCache() override;
  bool findSolution(std::string problem) override;
  std::string getSolution(std::string problem) override;
  void saveSolution(std::string problem, std::string solution) override;
};

#endif //SEARCHING_ALGORITHMS_SERVER__FILECACHEMANAGER_H_