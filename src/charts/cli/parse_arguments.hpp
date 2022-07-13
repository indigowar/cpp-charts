//
// Created by user on 7/13/22.
//

#ifndef CPP_CHARTS_PARSE_ARGUMENTS_HPP
#define CPP_CHARTS_PARSE_ARGUMENTS_HPP

#include <string_view>
#include <string>
#include <optional>
#include <vector>

namespace charts::cli {

enum status {
  Found,
  NotFound
};

struct flag final {
 std::string_view short_name;
 std::string_view long_name;
 std::string_view information;
 status foudStatus;
 std::optional<std::vector<std::string>> value;
};

struct command final {
  std::string_view name;
  std::string_view  information;
  std::vector<flag> flags;
  std::vector<std::string> args;
};

// parse the arguments and return the command with filled data.
command parse(const std::vector<command>& possible_commands, const std::vector<std::string>& args) {
  return command{};
}

}

#endif  // CPP_CHARTS_PARSE_ARGUMENTS_HPP
