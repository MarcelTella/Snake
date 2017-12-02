#include "catch.hpp"
#include "Snake.h"
#include "Position.h"

TEST_CASE( "Snake Head", "[Snake]" ){
    Snake s;
    Position head(3, 5);

    REQUIRE(s.getHeadPosition() == head);
}


TEST_CASE( "Snake Constructor", "[Snake]" ){
    Snake s;

    REQUIRE(s.length() == 3);
}

TEST_CASE( "Snake grow", "[Snake]" ){
    Snake s;
    Position nextPos(3, 6);
    s.grow(nextPos);

    REQUIRE(s.length() == 4);
    REQUIRE(s.getHeadPosition() == nextPos);
}

TEST_CASE( "Snake dead", "[Snake]" ){
    Snake s;

    REQUIRE(!s.amIDead());

    s.grow(Position(4, 5));
    REQUIRE(!s.amIDead());

    s.grow(Position(4, 4));
    REQUIRE(!s.amIDead());

    s.grow(Position(3, 4));
    REQUIRE(s.amIDead());
}


TEST_CASE( "Snake is over food", "[Snake]" ){
    Snake s;
    {
    Position food(3, 1);
    REQUIRE(s.overFood(food));
    }
    {
    Position food(5, 5);
    REQUIRE(!s.overFood(food));
    }
}
