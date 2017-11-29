set(EXECUTABLE_OUTPUT_PATH "bin")

set(SOURCES
    main.cpp
    Position.h
    Maths.h
    Maths.cpp
    Snake.h
    Snake.cpp
    Board.h
    Board.cpp
)

add_executable(Main ${SOURCES})
target_link_libraries(Main ${OpenCV_LIBS})
