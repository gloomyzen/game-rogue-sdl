/* Created by efreyu on 21.05.2020. */
#include <catch.hpp>
#include <iostream>
#include <memory>

namespace RogueSdl {
    namespace Test {
        TEST_CASE("check enabled tests...",
                "[runner test]") {
            int i = 5;
            REQUIRE(i == 5);
        }
    }
}
