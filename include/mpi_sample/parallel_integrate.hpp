#ifndef PARALLEL_INTEGRATE_HPP
#define PARALLEL_INTEGRATE_HPP
#include <boost/mpi/communicator.hpp>
#include <functional>
#include <parallel_integrate_export.hpp>

namespace mpi = boost::mpi;

namespace parallel {
/**
 * @brief Integrate a function using the trapezoidal rule in parallel.
 *
 * @param world The MPI communicator.
 * @param func The function to integrate.
 * @param start The start of the interval.
 * @param end The end of the interval.
 * @param num The number of trapezoids to use.
 * @return double The result of the integration.
 */
[[nodiscard]] double integrate(const mpi::communicator &world,
  const std::function<double(double)> &func,
  double start,
  double end,
  int num);
}// namespace parallel


#endif// PARALLEL_INTEGRATE_HPP