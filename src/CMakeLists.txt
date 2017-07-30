set(EXECUTABLE_OUTPUT_PATH "bin")
set(SOURCES
    Board.h
    Board.cpp
    Position.h
    Maths.h
    Maths.cpp
    main.cpp
)
add_executable(Main ${SOURCES})
