// cppcheck-suppress-file [uninitMemberVar, duplInheritedMember, duplInheritedMember, noExplicitConstructor]
#include <catch2/catch_test_macros.hpp>


#include <myproject/sample_library.hpp>

// FIXME: The macro here gets expanded and causes clang-tidy and cppcheck warnings
// Perhaps we should use a different testing framework, eg. Google Test.

// NOLINTBEGIN(cert-err58-cpp, cppcoreguidelines-avoid-do-while, misc-use-anonymous-namespace)
TEST_CASE("Factorials are computed", "[factorial]")
{
  REQUIRE(factorial(0) == 1);
  REQUIRE(factorial(1) == 1);
  REQUIRE(factorial(2) == 2);
  REQUIRE(factorial(3) == 6);
  REQUIRE(factorial(10) == 3628800);
}
// NOLINTEND(cert-err58-cpp, cppcoreguidelines-avoid-do-while, misc-use-anonymous-namespace)
