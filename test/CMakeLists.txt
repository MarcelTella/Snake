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
    ../src/DrawingHelper.h
    ../src/DrawingHelper.cpp
    testMaths.cpp
    testBoard.cpp
    testSnake.cpp
    test.cpp
    catch.hpp
)

add_executable(Tests ${SOURCES})
target_link_libraries(Tests ${OpenCV_LIBS} ${CURSES_LIBRARIES})
