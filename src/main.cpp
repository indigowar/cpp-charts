//
// Created by user on 7/13/22.
//
#include <iostream>

#include "charts/analysis/container_element.hpp"

using namespace charts::analysis;

void foo(container_element& e) {
  auto tags = e.tags().get();
  std::for_each(tags.begin(), tags.end(),
                [](auto& t) { std::cout << t << '\t'; });
}

int main() {
  tag_storage t;
  container_element el("Name", "Value", t, nullptr, nullptr);
  foo(el);
  return 0;
}