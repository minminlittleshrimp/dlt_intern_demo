cmake_minimum_required(VERSION 3.10)

project(hello_dlt)

find_package(PkgConfig)
pkg_check_modules(DLT REQUIRED automotive-dlt)

include_directories("${DLT_INCLUDE_DIRS}")
add_executable(hello_dlt hello_dlt.c)
target_link_libraries(hello_dlt ${DLT_LIBRARIES})


