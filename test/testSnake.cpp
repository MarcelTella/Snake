#include "catch.hpp"
#include "Snake.h"
#include "Position.h"

TEST_CASE( "Snake Head", "Check that the snake initial position." ){
    Snake s;
    Position head(3, 5);

    REQUIRE(s.getHeadPosition() == head);
}


TEST_CASE( "Snake Constructor", "Check the snake initial position." ){
    Snake s;

    REQUIRE(s.length() == 3);
}

TEST_CASE( "Snake grow", "Check that the snake grows." ){
    Snake s;
    Position nextPos(3, 6);
    s.grow(nextPos);

    REQUIRE(s.length() == 4);
    REQUIRE(s.getHeadPosition() == nextPos);
}

TEST_CASE( "Snake dead", "Check that the snake is in dead position." ){
    Snake s;

    REQUIRE(!s.amIDead());

    s.grow(Position(4, 5));
    REQUIRE(!s.amIDead());

    s.grow(Position(4, 4));
    REQUIRE(!s.amIDead());

    s.grow(Position(3, 4));
    REQUIRE(s.amIDead());
}


