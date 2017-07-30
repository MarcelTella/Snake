set(EXECUTABLE_OUTPUT_PATH "bin")

include_directories("../src")

set(SOURCES
    ../src/Position.h
    ../src/Board.h
    ../src/Board.cpp
    ../src/Maths.h
    ../src/Maths.cpp
    test.cpp
    testMaths.cpp
    testBoard.cpp
    catch.hpp
)

add_executable(Tests ${SOURCES})
