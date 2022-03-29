#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "regression.hpp"

#include <iostream>

#include "doctest.h"

TEST_CASE("testing regression") {
  regression reg{};

  REQUIRE(reg.size() == 0);

  SUBCASE("Fitting with two points") {
    reg.add(0., 1.);
    reg.add(1., 2.);
    auto result = reg.fit();
    CHECK(reg.size() == 2);
    CHECK(result.A == doctest::Approx(1.));
    CHECK(result.B == doctest::Approx(1.));
  }

  SUBCASE("Trying to fit with one point") {
    reg.add(0., 0.);
    CHECK_THROWS(reg.fit());
  }

  SUBCASE("Trying to fit with zero points") { CHECK_THROWS(fit(reg)); }
}