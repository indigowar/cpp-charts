//
// Created by user on 7/13/22.
//

#ifndef CPP_CHARTS_TAG_STORAGE_HPP
#define CPP_CHARTS_TAG_STORAGE_HPP

#include <algorithm>
#include <vector>

namespace charts::analysis {

enum tag { simple, linked, container, binary_tree, graph };

struct tag_storage final {
 private:
  std::vector<tag> tags;

 public:
  explicit tag_storage(std::vector<tag> t) : tags(std::move(t)) {}
  tag_storage() = default;
  ~tag_storage() = default;

  void add(tag t) noexcept { tags.push_back(t); }

  [[nodiscard]] std::vector<tag> get() const noexcept { return tags; }

  [[nodiscard]] bool contains(const tag& searched) const noexcept {
    if (tags.empty()) {
      return false;
    }

    return std::any_of(tags.begin(), tags.end(),
                       [&](const tag& t) { return t == searched; });
  }
};

tag_storage& createStorageWith(tag_storage& ts, tag t) {
  ts.add(t);
  return ts;
}

}  // namespace charts::analysis

#endif  // CPP_CHARTS_TAG_STORAGE_HPP
