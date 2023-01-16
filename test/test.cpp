#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../vehicles.cpp"

TEST_CASE("test input string", "[check_string_input]")
{
    REQUIRE(check_string_input("HONDA"));
    REQUIRE(check_string_input("H"));
    REQUIRE(!check_string_input("1"));
    REQUIRE(!check_string_input("-1"));
    REQUIRE(!check_string_input("M2"));
}

TEST_CASE("test input integer", "[check_input_int]")
{
    REQUIRE(check_input_int(2));
    REQUIRE(check_input_int(2005));
    REQUIRE(!check_input_int(-1));
    REQUIRE(check_input_int(4.5));
}
