#ifndef CACHEMANAGER_H_
#define CACHEMANAGER_H_
#include <string>


#include <map>
class CacheManager {

/**
 * CacheManager handles saving and loading of already defined solutions to problems
 * We can have different types of cache managers, providing different functionality, as needed.
 */


 public:
  virtual bool findSolution(std::string problem) = 0;
  virtual std::string getSolution(std::string problem) = 0;
  virtual void saveSolution(std::string problem, std::string solution, std::string filename) = 0;

};
#endif //CACHEMANAGER_H_
