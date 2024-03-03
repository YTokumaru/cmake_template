# cmake_template

[![ci](https://github.com/cpp-best-practices/cmake_template/actions/workflows/ci.yml/badge.svg)](https://github.com/cpp-best-practices/cmake_template/actions/workflows/ci.yml)
[![codecov](https://codecov.io/gh/cpp-best-practices/cmake_template/branch/main/graph/badge.svg)](https://codecov.io/gh/cpp-best-practices/cmake_template)
[![CodeQL](https://github.com/cpp-best-practices/cmake_template/actions/workflows/codeql-analysis.yml/badge.svg)](https://github.com/cpp-best-practices/cmake_template/actions/workflows/codeql-analysis.yml)

## About cmake_template

This is a C++ Best Practices GitHub template for getting up and running with C++ quickly.
    
TODO: Write about RelWithDebInfo build type
TOFIX: On Windows, ENABLE_DEVELOPER_MODE, ENABLE_CPP_CHECK_DEFAULT, ENABLE_CLANG_TIDY_DEFAULT are not parsed by CMake?
TODO: Write about options ${{ PROJECT_NAME }}_PACKAGING_MAINTAINER_MODE ${{ PROJECT_NAME }}_ENABLE_IPO 
TODO: Write about exporting configuration from Visual Studio
TODO: Write about debugging cmake files using --trace, --trace-source and --trace-expand
By default (collectively known as `ENABLE_DEVELOPER_MODE`)

 * Address Sanitizer and Undefined Behavior Sanitizer enabled where possible
 * Warnings as errors
 * clang-tidy and cppcheck static analysis
 * CPM for dependencies

It includes

 * a basic CLI example
 * examples for fuzz, unit, and constexpr testing
 * large github action testing matrix

It requires

 * cmake
 * a compiler


This project gets you started with a simple example of using FTXUI, which happens to also be a game.


## Getting Started

### Use the Github template
First, click the green `Use this template` button near the top of this page.
This will take you to Github's ['Generate Repository'](https://github.com/cpp-best-practices/cmake_template/generate) page.
Fill in a repository name and short description, and click 'Create repository from template'.
This will allow you to create a new repository in your Github account,
prepopulated with the contents of this project.

After creating the project please wait until the cleanup workflow has finished 
setting up your project and commited the changes.

Now you can clone the project locally and get to work!

    git clone https://github.com/<user>/<your_new_repo>.git

## More Details

 * [Dependency Setup](README_dependencies.md)
 * [Building Details](README_building.md)
 * [Docker](README_docker.md)

## Testing

See [Catch2 tutorial](https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md)

## Fuzz testing

See [libFuzzer Tutorial](https://github.com/google/fuzzing/blob/master/tutorial/libFuzzerTutorial.md)

## Known Issues

- Testing framework heavily uses macros, and is difficult to configure static analysis on the test files (It checks the expanded `#define` and outputs errors). Therefore, `cppcheck` and `clang-tidy` has deliberately been turn off for testing targets. CMake 2.27 seems to support the feature `SKIP_LINTING` which could help solve the issue in a more elegant way, but since cmake 2.27 is not widely distributed through `apt`, target compile properties has been modified in `tests/CMakeLists.txt`