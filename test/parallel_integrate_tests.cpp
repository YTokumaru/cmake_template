#include <boost/mpi/communicator.hpp>
#include <boost/mpi/environment.hpp>
#include <boost/math/constants/constants.hpp>
#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include <functional>
#include <parallel_integrate.hpp>

namespace mpi = boost::mpi;
namespace math = boost::math;

TEST_CASE("Parallel integration of a function", "[parallel_integrate]")
{
  const mpi::environment env;
  const mpi::communicator world;
  auto func = [](double x) { return 1 / (x * x + 1); };
  const double result = parallel::integrate(world, func, 0.0, 1.0, 2e9) * 4;
  if (world.rank() == 0) { REQUIRE_THAT(result, Catch::Matchers::WithinRel(math::constants::pi<double>(), 1e-3)); }
  env.~environment();
}