#include "catch.hpp"
#include "Maths.h"

TEST_CASE( "Maths", "modulo" ){
    REQUIRE(modulo(-1, 2) == 1);
    REQUIRE(modulo(1, 2) == 1);
    REQUIRE(modulo(3, 2) == 1);
    REQUIRE(modulo(-3, 2) == 1);
    REQUIRE(modulo(-3, 2) != 0);
}
