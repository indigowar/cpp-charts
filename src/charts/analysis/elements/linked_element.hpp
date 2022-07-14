//
// Created by user on 7/13/22.
//

#ifndef CPP_CHARTS_LINKED_ELEMENT_HPP
#define CPP_CHARTS_LINKED_ELEMENT_HPP

#include <memory>

#include "element.hpp"

namespace charts::analysis {

class linked_element : public element {
 public:
  linked_element(std::string n, std::string v, tag_storage& ts,
                 std::shared_ptr<element> next)
      : element(std::move(n), std::move(v), createStorageWith(ts, tag::linked)),
        m_next(std::move(next)) {}

  [[nodiscard]] std::shared_ptr<element> next() const noexcept {
    return m_next;
  }

 private:
  std::shared_ptr<element> m_next;
};

}  // namespace charts::analysis
#endif  // CPP_CHARTS_LINKED_ELEMENT_HPP
