#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include <serial_integrate.hpp>

TEST_CASE("Integrate a simple function", "[integrate]")
{
  const auto f = [](double x) { return x * x; };
  const double a = 0.0;
  const double b = 1.0;
  const int n = 100;
  const double expected = 1.0 / 3.0;
  const double result = serial::integrate(f, a, b, n);
  REQUIRE_THAT(result, Catch::Matchers::WithinRel(expected, 1e-3));
}