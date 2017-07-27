cmake_minimum_required (VERSION 2.6)
project (Snake)

message(STATUS "Trying to include Eigen library")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
find_package (Eigen3 3.3 REQUIRED NO_MODULE)
include_directories(${EIGEN3_INCLUDE_DIR})
message(STATUS "EIGEN:  ${EIGEN3_VERSION}  (internal)")

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(libs)
