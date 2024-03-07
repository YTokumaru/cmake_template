# CMake Template

[![build(Windows)](https://github.com/YTokumaru/cpp-project-kickstarter/actions/workflows/build-windows.yml/badge.svg)](https://github.com/YTokumaru/cpp-project-kickstarter/actions/workflows/build-windows.yml)
[![build(Ubuntu)](https://github.com/YTokumaru/cpp-project-kickstarter/actions/workflows/build-ubuntu.yml/badge.svg)](https://github.com/YTokumaru/cpp-project-kickstarter/actions/workflows/build-ubuntu.yml)
[![build(MacOS)](https://github.com/YTokumaru/cpp-project-kickstarter/actions/workflows/build-macos.yml/badge.svg)](https://github.com/YTokumaru/cpp-project-kickstarter/actions/workflows/build-macos.yml)
[![codecov](https://codecov.io/gh/YTokumaru/cpp-project-kickstarter/graph/badge.svg?token=OUBFIJTUCP)](https://codecov.io/gh/YTokumaru/cpp-project-kickstarter)
[![CodeQL](https://github.com/YTokumaru/cpp-project-kickstarter/actions/workflows/codeql-analysis.yml/badge.svg)](https://github.com/YTokumaru/cpp-project-kickstarter/actions/workflows/codeql-analysis.yml)

## About C++ Project Kickstarter

This is a CMake project template to get you started with modern C++ project. Works on Windows, Linux, and MacOS.
This project aims to work seemlessly on major operating systems and without a lengthy setup process. Just install the dependencies through default package manager and you are good to go 🚀!

This template comes with features that help you write bug/error prone code and make it easier to maintain and scale your project:

- Easy configuration using CMake Presets
- Address Sanitizer and Undefined Behavior Sanitizer enabled where possible
- Warnings as errors
- clang-tidy and cppcheck static analysis
- CPM for dependencies
- Code coverage with codecov
- Continuous integration on three operating systems

The initial project includes:

- a basic CLI example
- examples for fuzz, unit, and constexpr testing

## Getting Started

### Use the Github template

First, click the green `Use this template` button near the top of this page.
This will take you to Github's ['Generate Repository'](https://github.com/ytokumaru/cpp-project-kickstarter/generate) page.
Fill in a repository name and short description, and click 'Create repository from template'.
This will allow you to create a new repository in your Github account,
prepopulated with the contents of this project.

After creating the project please wait until the cleanup workflow has finished
setting up your project and commited the changes.

Now you can clone the project locally and get to work!

    git clone https://github.com/<user>/<your_new_repo>.git

### Setting up the dependencies

#### Windows

Before you start, we recommend you to install a package manager [Chocolatey](https://chocolatey.org/install) to install the dependencies. It makes installing tools like clang-tidy and cppcheck much easier.

- Install Visual Studio 2022 or Visual Studio Build Tools 2022

If you want to use Visual Studio as your IDE, install Visual Studio 2022. If you want to use other editors, install Visual Studio Build Tools 2022.

  - Install using gui
Download the installer from [Visual Studio 2022](https://visualstudio.microsoft.com/downloads/).
Run the installer and select the "Desktop development with C++" workload.
If you want to be able to compile with clang, search for "clang" in the individual components tab and install the "Clang compiler for Windows" component and "MSBuild Support for llvm toolset".
You can change the configuration later from the installer.

Alternatively, you can use choco to install Visual Studio / Visual Studio Build Tools 2022.

```powershell
# Install Visual Studio Build Tools 2022
choco install visualstudio2022buildtools --package-parameters "--config path-to-this-project's-.vsconfig"

# Install Visual Studio 2022
choco install visualstudio2022community --package-parameters "--config path-to-this-project's-.vsconfig"
```

- Install ccache

```powershell
choco install ccache
```

- Install cppcheck

```powershell
choco install cppcheck
```

- Install vswhere

```powershell
choco install vswhere
```

#### Debian/Ubuntu

```bash
sudo apt update
sudo apt install -y gcc g++ clang clang-tools clang-tidy llvm cmake ninja-build ccache cppcheck gcovr
```

#### MacOS

```zsh
brew install gcc llvm cmake ninja ccache cppcheck
```

### Configure, Build, and Test

Building is made easy with CMake Presets. You can configure and build the project with the following commands from the root of the project:

```bash
cmake --preset <preset_name>
cmake --build --preset build-<preset_name>
ctest --preset test-<preset_name>
```
`<preset_name>` can be one of the following:
- `windows-msvc-debug`
- `windows-msvc-release`
- `unixlike-clang-debug`
- `unixlike-clang-release`
- `unixlike-gcc-debug`
- `unixlike-gcc-release`

Feel free to modify the presets to your liking in `CMakePresets.json`.

## Experiencing issues?

### Debugging CMakefile

Use options `--trace`, `--trace-source FILENAME`, `-trace-expand` when configuring cmake project to debug cmakefile

### Known Issues

- Testing framework heavily uses macros, and is difficult to configure static analysis on the test files (It checks the expanded `#define` and outputs errors). Therefore, `cppcheck` and `clang-tidy` has deliberately been turn off for testing targets. CMake 2.27 seems to support the feature `SKIP_LINTING` which could help solve the issue in a more elegant way, but since cmake 2.27 is not widely distributed through `apt`, target compile properties has been modified in `tests/CMakeLists.txt`
- Due to the issue where [ubuntu-latest runners have an incompatible combination of clang and libstdc++](https://github.com/actions/runner-images/issues/8659), so using github action to setup the environment. When the issue is fixed, The code should compile without any configuration.

### Still having issues?
Open a new issue and we will help you out!
