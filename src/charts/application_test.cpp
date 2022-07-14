//
// Created by user on 7/13/22.
//
#include <catch2/catch_test_macros.hpp>

#include "application.hpp"

TEST_CASE("Application is working", "[application]") {
  charts::application app(0, nullptr);

  REQUIRE(app.run() == EXIT_SUCCESS);
}