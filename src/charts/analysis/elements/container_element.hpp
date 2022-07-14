//
// Created by user on 7/13/22.
//

#ifndef CPP_CHARTS_CONTAINER_ELEMENT_HPP
#define CPP_CHARTS_CONTAINER_ELEMENT_HPP

#include "linked_element.hpp"

namespace charts::analysis {

class container_element : public linked_element {
 public:
  container_element(std::string n, std::string v, tag_storage& ts,
                    std::shared_ptr<element> next,
                    std::shared_ptr<element> child)
      : linked_element(std::move(n), std::move(v),
                       createStorageWith(ts, tag::container), std::move(next)),
        m_child{std::move(child)} {}

  [[nodiscard]] std::shared_ptr<element> child() const noexcept {
    return m_child;
  }

 private:
  std::shared_ptr<element> m_child;
};

}  // namespace charts::analysis

#endif  // CPP_CHARTS_CONTAINER_ELEMENT_HPP
