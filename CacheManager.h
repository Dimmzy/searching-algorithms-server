//
// Created by haim on 14/01/2020.
//

#ifndef CACHEMANAGER_H_
#define CACHEMANAGER_H_
#include <string>

class CacheManager {
 public:
  virtual bool findSolution(std::string problem) = 0;
  virtual std::string getSolution(std::string problem) = 0;
  virtual void saveSolution(std::string problem, std::string solution) = 0;

};
#endif //CACHEMANAGER_H_
