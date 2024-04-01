#ifndef SAMPLE_LIBRARY_HPP
#define SAMPLE_LIBRARY_HPP

#include <myproject/sample_library_export.hpp>

[[nodiscard]] SAMPLE_LIBRARY_EXPORT int factorial(int) noexcept;

[[nodiscard]] constexpr unsigned int factorial_constexpr(int unsigned input) noexcept
{
  if (input == 0) { return 1; }

  return input * factorial_constexpr(input - 1);
}

#endif
