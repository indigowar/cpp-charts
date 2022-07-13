//
// Created by user on 7/13/22.
//
#include "parse_arguments.hpp"

#include <catch2/catch_test_macros.hpp>

using namespace charts::cli;

flag isDebug{
    "-d",
    "--debug",
    "Set debug mode on the program",
    status::NotFound,
    std::nullopt
};

flag target{
    "-t",
    "--target",
    "Set the target for create command",
    status::NotFound,
    std::optional<std::vector<std::string>>{}
};

flag giveCoffee{
    "-c",
    "--coffee",
    "Get the coffee from program",
    status::NotFound,
    std::nullopt,
};

command create{
    "create",
    "create a set of charts",
    std::vector<flag>{isDebug, target},
    std::vector<std::string>{}
};

command shutdown{
    "shutdown",
    "shutdown the computer",
    std::vector<flag>{isDebug},
    std::vector<std::string>{}
};

TEST_CASE("Parsing console arguments", "[charts::cli::parse]") {
  std::vector<std::string> args{
      "charts",
      "--debug",
      "create",
      "-t",
      "main.cpp",
      "level.hpp",
      "level.cpp"
  };

  SECTION("Checking is args has debug") {
    auto result = parse(std::vector<command>{shutdown, create}, args);
    REQUIRE(result.name == "create");
    REQUIRE(result.args.size() == 2);
    REQUIRE(result.flags.size() == 2);
    REQUIRE(result.flags[0].long_name == "--debug");
  }

}