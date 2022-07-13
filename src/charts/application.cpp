//
// Created by user on 7/13/22.
//

#include "application.hpp"

namespace charts {
application::application(int argc, char **argv) : args(argc){
  for(size_t i{}; i != argc; i++) {
    args[i] = std::string{argv[i]};
  }
}

application::~application() {}

int application::run() {
  return EXIT_SUCCESS;
}

}  // namespace charts