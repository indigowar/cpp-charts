//
// Created by user on 7/13/22.
//

#ifndef CPP_CHARTS_APPLICATION_H
#define CPP_CHARTS_APPLICATION_H

#include <vector>
#include <string>

namespace charts {

// main class of application
class application {
 public:
  application(int, char **);
  ~application();

  // the internal main function
  int run();

 private:
  std::vector<std::string> args;
};

}  // namespace charts

#endif  // CPP_CHARTS_APPLICATION_H
