/* Created by efreyu on 21.05.2020. */
#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

int main(int argc, char* argv[]) {
    using namespace ModernCppCI;

    auto result = Catch::Session().run(argc, argv);

    return (result < 0xff ? result : 0xff);
}