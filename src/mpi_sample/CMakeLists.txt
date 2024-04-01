include(GenerateExportHeader)

if(myproject_USE_SYSTEM_BOOST)
  find_package(Boost REQUIRED COMPONENTS mpi)
endif()

add_library(serial_integrate serial_integrate.cpp)
add_library(myproject::serial_integrate ALIAS serial_integrate)
target_link_libraries(
    serial_integrate
    PRIVATE
    myproject_options
    myproject_warnings
)
target_include_directories(serial_integrate ${WARNING_GUARD} PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
                                                                  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>)
target_compile_features(
    serial_integrate
    PUBLIC
    cxx_std_20
)
set_target_properties(
    serial_integrate
    PROPERTIES
    CXX_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN YES
)
generate_export_header(
    serial_integrate
    EXPORT_FILE_NAME ${CMAKE_BINARY_DIR}/include/serial_integrate_export.hpp
)
if(NOT BUILD_SHARED_LIBS)
    target_compile_definitions(
        serial_integrate
        PUBLIC
        SERIAL_INTEGRATE_STATIC_DEFINE
    )
endif()

add_library(parallel_integrate parallel_integrate.cpp)
add_library(myproject::parallel_integrate ALIAS parallel_integrate)
target_link_libraries(
    parallel_integrate
    PRIVATE
    myproject::myproject_options
    myproject::myproject_warnings
    myproject::serial_integrate
)
if(myproject_USE_SYSTEM_BOOST)
  target_link_system_libraries(
      parallel_integrate
      PUBLIC
      Boost::mpi
  )
else()
  target_link_system_libraries(
      parallel_integrate
      PRIVATE
      boost_mpi
  )
endif()
target_include_directories(parallel_integrate ${WARNING_GUARD} PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
                                                                     $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>)
target_compile_features(
    parallel_integrate
    PUBLIC
    cxx_std_20
)
set_target_properties(
    parallel_integrate
    PROPERTIES
    CXX_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN YES
)
generate_export_header(
    parallel_integrate
    EXPORT_FILE_NAME ${CMAKE_BINARY_DIR}/include/parallel_integrate_export.hpp
)
if(NOT BUILD_SHARED_LIBS)
    target_compile_definitions(
        parallel_integrate
        PUBLIC
        PARALLEL_INTEGRATE_STATIC_DEFINE
    )
endif()