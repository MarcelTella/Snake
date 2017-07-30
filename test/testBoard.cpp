#include "catch.hpp"
#include "Position.h"
#include "Board.h"

TEST_CASE( "Board", "Choosing direction 1" ){
    Position pos(0, 0);
    Position newPos;

    Board b(2, 2);

    newPos = b.getNext(LEFT, pos);
    Position shouldBePos(1, 0);
    REQUIRE(newPos == shouldBePos);

    newPos = b.getNext(RIGHT, pos);
    shouldBePos = Position(1, 0);
    REQUIRE(newPos == shouldBePos);

    newPos = b.getNext(TOP, pos);
    shouldBePos = Position(0, 1);
    REQUIRE(newPos == shouldBePos);

    newPos = b.getNext(BOTTOM, pos);
    shouldBePos = Position(0, 1);
    REQUIRE(newPos == shouldBePos);
}

TEST_CASE( "Bigger Dimensions Board", "More realistic case size 10 - Choosing direction 2" ){
    Position pos(9, 9);
    Position newPos;

    Board b(10, 10);

    newPos = b.getNext(LEFT, pos);
    Position shouldBePos(8, 9);
    REQUIRE(newPos == shouldBePos);

    newPos = b.getNext(RIGHT, pos);
    shouldBePos = Position(0, 9);
    REQUIRE(newPos == shouldBePos);

    newPos = b.getNext(TOP, pos);
    shouldBePos = Position(9, 8);
    REQUIRE(newPos == shouldBePos);

    newPos = b.getNext(BOTTOM, pos);
    shouldBePos = Position(9, 0);
    REQUIRE(newPos == shouldBePos);
}

TEST_CASE( "Next position is food", "Next position is food" ){
    Board b(10, 10);
    Position food = b.getFood();

    Position rightToFood = b.getNext(RIGHT, food);
    REQUIRE(b.isNextFood(rightToFood, LEFT));
    REQUIRE(!b.isNextFood(rightToFood, RIGHT));
    REQUIRE(!b.isNextFood(rightToFood, TOP));
    REQUIRE(!b.isNextFood(rightToFood, BOTTOM));
}
