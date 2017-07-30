set(EXECUTABLE_OUTPUT_PATH "bin")

include_directories("../src")

set(SOURCES
    ../src/Position.h
    ../src/Board.h
    ../src/Board.cpp
    ../src/Maths.h
    ../src/Maths.cpp
    ../src/Snake.cpp
    ../src/Snake.h
    test.cpp
    testMaths.cpp
    testBoard.cpp
    testSnake.cpp
    catch.hpp
)

add_executable(Tests ${SOURCES})
