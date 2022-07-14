//
// Created by user on 7/13/22.
//
#ifndef CPP_CHARTS_ELEMENT_HPP
#define CPP_CHARTS_ELEMENT_HPP

#include <string>

#include "charts/analysis/tag_storage.hpp"

namespace charts::analysis {

// element implements logic of basic element in the code.
class element {
 public:
  element(std::string n, std::string v, tag_storage ts)
      : m_name{std::move(n)},
        m_value{std::move(v)},
        m_storage(createStorageWith(ts, tag::simple)) {}

  [[nodiscard]] tag_storage tags() const noexcept { return m_storage; }

  [[nodiscard]] std::string name() const noexcept { return m_name; }

  [[nodiscard]] std::string value() const noexcept { return m_value; }

 private:
  std::string m_name;
  std::string m_value;
  tag_storage m_storage;
};

}  // namespace charts::analysis
#endif  // CPP_CHARTS_ELEMENT_HPP
