//
// Created by user on 7/13/22.
//

#ifndef CPP_CHARTS_BINARY_TREE_ELEMENT_HPP
#define CPP_CHARTS_BINARY_TREE_ELEMENT_HPP

#include <memory>

#include "element.hpp"

namespace charts::analysis {

class binary_tree_element : public element {
 public:
  binary_tree_element(std::string n, std::string v, tag_storage& ts,
                      std::shared_ptr<element> left,
                      std::shared_ptr<element> right)
      : element(std::move(n), std::move(v),
                createStorageWith(ts, tag::binary_tree)),
        m_left(std::move(left)),
        m_right(std::move(right)) {}

  [[nodiscard]] std::shared_ptr<element> left() const noexcept {
    return m_left;
  }

  [[nodiscard]] std::shared_ptr<element> right() const noexcept {
    return m_right;
  }

 private:
  std::shared_ptr<element> m_left;
  std::shared_ptr<element> m_right;
};

}  // namespace charts::analysis

#endif  // CPP_CHARTS_BINARY_TREE_ELEMENT_HPP
