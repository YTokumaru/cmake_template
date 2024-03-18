include(GenerateExportHeader)

if(myproject_USE_SYSTEM_BOOST)
  find_package(Boost REQUIRED COMPONENTS mpi)
endif()
# ---- Dependencies ----
include(${Catch2_SOURCE_DIR}/extras/Catch.cmake)

add_executable(serial_integrate_tests serial_integrate_tests.cpp)
target_link_libraries(
  serial_integrate_tests
  PRIVATE 
          myproject::myproject_warnings
          myproject::myproject_options
          myproject::serial_integrate)
target_link_system_libraries(serial_integrate_tests PRIVATE boost_mpi Catch2::Catch2WithMain)
set_target_properties(serial_integrate_tests PROPERTIES CXX_CPPCHECK "")
set_target_properties(serial_integrate_tests PROPERTIES CXX_CLANG_TIDY "")
catch_discover_tests(
  serial_integrate_tests
  TEST_PREFIX
  "serial_integrate."
  REPORTER
  XML
  OUTPUT_DIR
  .
  OUTPUT_PREFIX
  "serial_integrate."
  OUTPUT_SUFFIX
  .xml)

add_executable(parallel_integrate_tests parallel_integrate_tests.cpp)
target_link_libraries(
  parallel_integrate_tests
  PRIVATE 
          myproject::myproject_warnings
          myproject::myproject_options
          myproject::parallel_integrate)
if(myproject_USE_SYSTEM_BOOST)
  target_link_system_libraries(parallel_integrate_tests PRIVATE Boost::mpi)
else()
  target_link_system_libraries(parallel_integrate_tests PRIVATE boost_mpi boost_math)
endif()
target_link_system_libraries(
  parallel_integrate_tests
  PRIVATE
  Catch2::Catch2WithMain)
set_target_properties(parallel_integrate_tests PROPERTIES CXX_CPPCHECK "")
set_target_properties(parallel_integrate_tests PROPERTIES CXX_CLANG_TIDY "")
add_test(NAME parallel_integrate_tests COMMAND mpiexec -np ${myproject_NPROC} $<TARGET_FILE:parallel_integrate_tests>)