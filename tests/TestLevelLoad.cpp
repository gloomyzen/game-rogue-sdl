/* Created by efreyu on 17.05.2020. */

#include <gtest/gtest.h>
#include "../src/Classes/Utilities/JsonLoadManager.h"

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

/*TEST(JSON, JsonOpen) {
//    FILE* fp = fopen("resources/data/level1.json", "r");
    std::ifstream ifs("../resources/data/level1.json");
    rapidjson::IStreamWrapper isw(ifs);

    rapidjson::Document d;
    d.ParseStream(isw);
    if (d.HasParseError()) {
        std::cout << d.GetParseError() << std::endl;
    }
//    rapidjson::Value::MemberIterator level = d.FindMember("level");
    EXPECT_EQ(d.IsObject(),true);
//    EXPECT_EQ(level->value.IsArray(),true);
//    ASSERT_TRUE(d.IsObject());
}*/

/*
 * test without constructor
 */
TEST(LevelLoad, FirstLoadLevel) {
    const char* file = "../resources/data/level1.json";
    JsonLoadManager manager1;
    manager1.loadFile(file);
    EXPECT_EQ(manager1.getPath(), file);
    ASSERT_TRUE(manager1.isLoaded());
}

/*
 * test with constructor
 */
TEST(LevelLoad, SecondLoadLevel) {
    const char* file = "../resources/data/level1.json";
    JsonLoadManager manager1(file);
    EXPECT_EQ(manager1.getPath(), file);
    ASSERT_TRUE(manager1.isLoaded());
}

