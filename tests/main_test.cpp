#include "utf-8-parse/utf-8-parse.h"
#include "catch_amalgamated.hpp"

TEST_CASE("General utf-8 library test", "[utf-8]"){

    char data[] = "\u0024\u0400\u20AC\U00010348\u0025";
    const auto size = sizeof(data);

    auto pos0 = next_pos_utf8(data, -1, size);
    REQUIRE(pos0 == 0);
    auto value0_length = get_utf8_field_length(data, pos0, size);
    REQUIRE(value0_length == 1);
    auto value0 = get_utf8_symbol(data, pos0, size);
    REQUIRE(value0 == 0x24);
    
    auto pos1 = next_pos_utf8(data, pos0, size);
    REQUIRE(pos1 == 1);
    auto value1_length = get_utf8_field_length(data, pos1, size);
    REQUIRE(value1_length == 2);
    auto value1 = get_utf8_symbol(data, pos1, size);
    REQUIRE(value1 == 0x400);
    
    auto pos2 = next_pos_utf8(data, pos1, size);
    REQUIRE(pos2 == 3);
    auto value2_length = get_utf8_field_length(data, pos2, size);
    REQUIRE(value2_length == 3);
    auto value2 = get_utf8_symbol(data, pos2, size);
    REQUIRE(value2 == 0x20AC);
    

    auto pos3 = next_pos_utf8(data, pos2, size);
    REQUIRE(pos3 == 6);
    auto value3_length = get_utf8_field_length(data, pos3, size);
    REQUIRE(value3_length == 4);
    auto value3 = get_utf8_symbol(data, pos3, size);
    REQUIRE(value3 == 0x10348);

    auto pos4 = next_pos_utf8(data, pos3, size);
    REQUIRE(pos4 == 10);
    auto value4_length = get_utf8_field_length(data, pos4, size);
    REQUIRE(value4_length == 1);
    auto value4 = get_utf8_symbol(data, pos4, size);
    REQUIRE(value4 == 0x25);

    auto pos5 = next_pos_utf8(data, pos4, size);
    REQUIRE(pos5 == 11);
    auto value5_length = get_utf8_field_length(data, pos5, size);
    REQUIRE(value5_length == 1);
    auto value5 = get_utf8_symbol(data, pos5, size);
    REQUIRE(value5 == 0x0);

    auto pos6 = next_pos_utf8(data, pos5, size);
    REQUIRE(pos6 == 12);
    auto value6_length = get_utf8_field_length(data, pos6, size);
    REQUIRE(value6_length == 0);
    auto value6 = get_utf8_symbol(data, pos6, size);
    REQUIRE(value6 == 0x0);

    auto pos7 = next_pos_utf8(data, size + 1, size);
    REQUIRE(pos7 == -1);

}