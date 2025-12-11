cmake_minimum_required(VERSION 3.20)
project(Physical_Modeling_Library LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall -Wextra -Werror)

option(BUILD_TESTS "Build test executable" ON)

add_executable(main main.cpp)

if(BUILD_TESTS)

include(FetchContent)
  FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG main
	)
  FetchContent_MakeAvailable(googletest)

  add_executable(test test.cpp tests/quantity.cpp)

  target_compile_definitions(test PRIVATE
    TEST_CONSTRUCT
    TEST_ADD_SUB
    # TEST_UNARY
    # TEST_DIM_MUL_DIV
    # TEST_SCALAR_OPS
    # TEST_COMPARISONS
    # TEST_COMPILETIME
    # TEST_LITERALS
  )
  
  target_link_libraries(test 
    PRIVATE 
      GTest::gtest 
      GTest::gmock
  )
endif()

# Helper clean targets
set(PML_PROJECT_ROOT "${CMAKE_SOURCE_DIR}")

add_custom_target(clear_cmake
  COMMAND ${CMAKE_COMMAND} -E rm -f
    "${PML_PROJECT_ROOT}/CMakeCache.txt"
    "${PML_PROJECT_ROOT}/cmake_install.cmake"
    "${PML_PROJECT_ROOT}/Makefile"
  COMMAND ${CMAKE_COMMAND} -E rm -rf
    "${PML_PROJECT_ROOT}/CMakeFiles"
    "${PML_PROJECT_ROOT}/_deps"
  COMMENT "Remove CMake cache and generated files"
)

add_custom_target(clear_bins
  COMMAND ${CMAKE_COMMAND} -E rm -f
    "${PML_PROJECT_ROOT}/main"
    "${PML_PROJECT_ROOT}/test"
    "${PML_PROJECT_ROOT}/test_main"
  COMMENT "Remove built executables"
)

add_custom_target(clear_tests
  COMMAND ${CMAKE_COMMAND} -E rm -rf
    "${PML_PROJECT_ROOT}/tests/CMakeFiles"
    "${PML_PROJECT_ROOT}/tests/Testing"
    "${PML_PROJECT_ROOT}/tests/CTestTestfile.cmake"
    "${PML_PROJECT_ROOT}/tests/CTestTestfile.cmake.depend"
  COMMENT "Remove test runner artifacts"
)

add_custom_target(clear_all
  COMMENT "Remove build outputs, CMake cache, and test artifacts"
)

add_dependencies(clear_all clear_cmake clear_bins clear_tests)
