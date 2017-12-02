cmake_minimum_required (VERSION 2.6)
project (Snake)

#Eigen
message(STATUS "Trying to include Eigen library")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
find_package (Eigen3 3.1.2)
include_directories(${EIGEN3_INCLUDE_DIR})
message(STATUS "EIGEN:  ${EIGEN3_VERSION}  (internal)")

#OpenCV
find_package( OpenCV REQUIRED )
message(STATUS "OpenCV:version: ${OpenCV_VERSION}")
include_directories(${OpenCV_INCLUDE_DIRS})

#NCurses-Keystroke capturing
find_package(Curses REQUIRED)
message(STATUS "Curses:version: ${Curses_VERSION}")
include_directories(${CURSES_INCLUDE_DIR})

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(libs)
