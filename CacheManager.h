#ifndef CACHEMANAGER_H_
#define CACHEMANAGER_H_

#include <string>


#include <map>

/**
 * CacheManager handles saving and loading of already defined solutions to problems
 * We can have different types of cache managers, providing different functionality, as needed.
 */
class CacheManager {
 public:
  virtual void loadToCache() = 0;
  virtual bool findSolution(std::string problem) = 0;
  virtual std::string getSolution(std::string fileName) = 0;
  virtual void saveSolution(std::string problem, std::string solution) = 0;
  virtual ~CacheManager() = default;
};
#endif //CACHEMANAGER_H_
