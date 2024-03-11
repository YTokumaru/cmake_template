#include <functional>
#include <boost/mpi/communicator.hpp>
#include <boost/mpi/collectives.hpp>

#include <mpi_sample/parallel_integrate.hpp>
#include <mpi_sample/serial_integrate.hpp>

namespace mpi = boost::mpi;

double parallel::integrate(const mpi::communicator &world, const std::function<double(double)> &func, double start, double end, int num)
{
    // Each process will calculate its own local result
    const int rank = world.rank();
    const int size = world.size();
    const double delta = (end - start) / num;
    const int local_n = num / size;
    const double local_start = start + rank * local_n * delta;
    const double local_end = local_start + local_n * delta;
    const double local_result = serial::integrate(func, local_start, local_end, local_n);
    double result = 0.0;

    // The root process will receive the local results and sum them up
    if (rank == 0)
    {
        mpi::reduce(world, local_result, result, std::plus<>(), 0);
    }
    else
    {
        mpi::reduce(world, local_result, std::plus<>(), 0);
    }
    return result;
}