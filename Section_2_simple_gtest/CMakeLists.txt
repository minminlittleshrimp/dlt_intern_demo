cmake_minimum_required(VERSION 3.10)
project(hellodlt)

# Add DLT daemon include directory if necessary
include_directories(
    ${DLT_INCLUDE_DIRS}
)

# Enable testing
enable_testing()

# Find GTest package
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

#tim pakage
find_package(PkgConfig)
pkg_check_modules(DLT REQUIRED automotive-dlt)

# Add executable for the test
add_executable(gtest_hello_dlt gtest_hello_dlt.cpp hello_dlt.cpp)

# Add flags for coverage
set(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
set(CMAKE_C_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")

# Link GTest libraries
target_link_libraries(gtest_hello_dlt ${GTEST_LIBRARIES} ${DLT_LIBRARIES} pthread)

# Add the test
add_test(NAME gtest_hello_dlt COMMAND gtest_hello_dlt)
