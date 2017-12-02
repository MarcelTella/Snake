set(EXECUTABLE_OUTPUT_PATH "bin")

set(SOURCES
    Board.h
    Board.cpp
    Position.h
    Maths.h
    Maths.cpp
    Snake.h
    Snake.cpp
    general.h
    main.cpp
)

add_executable(Main ${SOURCES})
target_link_libraries(Main ${OpenCV_LIBS} ${CURSES_LIBRARIES})
