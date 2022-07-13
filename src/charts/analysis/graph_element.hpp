//
// Created by user on 7/13/22.
//

#ifndef CPP_CHARTS_GRAPH_ELEMENT_HPP
#define CPP_CHARTS_GRAPH_ELEMENT_HPP

#include <memory>

#include "element.hpp"

namespace charts::analysis {

class graph_element : public element {
 public:
  graph_element(std::string n, std::string v, tag_storage& ts,
                std::vector<std::shared_ptr<element>> children)
      : element(std::move(n), std::move(v), createStorageWith(ts, tag::graph)),
        m_children(std::move(children)) {}

  [[nodiscard]] std::vector<std::shared_ptr<element>> children()
      const noexcept {
    return m_children;
  }

  [[nodiscard]] bool contains(std::shared_ptr<element> ptr) {
    return std::any_of(m_children.cbegin(), m_children.cend(),
                       [&](const std::shared_ptr<element>& item) -> bool {
                         return ptr->name() == item->name() &&
                                ptr->value() == ptr->value();
                       });
  }

  void add_child(const std::shared_ptr<element>& ptr) noexcept {
    m_children.push_back(ptr);
  }

 private:
  std::vector<std::shared_ptr<element>> m_children;
};

}  // namespace charts::analysis
#endif  // CPP_CHARTS_GRAPH_ELEMENT_HPP
