//
// Created by user on 7/13/22.
//

#include "application.hpp"

#include <iostream>

#include "charts/analysis/elements/container_element.hpp"

namespace charts {
application::application(int argc, char **argv) : args(argc){
  for(size_t i{}; i != argc; i++) {
    args[i] = std::string{argv[i]};
  }
}

application::~application() = default;

void foo(analysis::container_element& e) {
  auto tags = e.tags().get();

  std::for_each(tags.begin(), tags.end(), [](auto& t){std::cout << t << '\t'; });
}

int application::run() {
  analysis::tag_storage t;

  analysis::container_element el("Name", "Value", t, nullptr, nullptr);
  foo(el);

  return EXIT_SUCCESS;
}

}  // namespace charts