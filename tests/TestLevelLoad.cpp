/* Created by efreyu on 17.05.2020. */

#include <gtest/gtest.h>
#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>
#include <fstream>

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

TEST(LevelLoad, FirstLoadLevel) {
    LoadManager
}

