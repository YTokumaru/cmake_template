function(myproject_enable_coverage project_name)
 if(NOT CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(WARNING "Coverage is only available in Debug mode")
    return()
  endif()
  if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
    if(WIN32)
      # There is a bug regarding --coverage on Visual Studio llvm toolchain manual linking is required to circumvent
      # https://bugs.llvm.org/show_bug.cgi?id=40877
      execute_process(
        COMMAND cmd /c "C:\\Program Files (x86)\\Microsoft Visual Studio\\Installer\\vswhere.exe" -latest -products * -find  **/lib/clang/17/lib/windows/clang_rt.profile-x86_64.lib
        OUTPUT_VARIABLE LIB_INSTALL_DIR
        OUTPUT_STRIP_TRAILING_WHITESPACE
      )
      target_link_libraries(${project_name} INTERFACE "${LIB_INSTALL_DIR}")
    endif()
    target_compile_options(${project_name} INTERFACE --coverage)
    target_link_libraries(${project_name} INTERFACE --coverage)
  endif()
endfunction()
