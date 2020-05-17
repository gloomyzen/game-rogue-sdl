/* Created by efreyu on 17.05.2020. */

#include <gtest/gtest.h>
#include "rapidjson/document.h"

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(TestJsonDeps, IncludeJsonTest) {
    const char json[] = " { \"test\" : \"row\", \"t\" : true , \"f\" : false } ";
    rapidjson::Document document;
    document.Parse(json);

    ASSERT_TRUE(document.IsObject());
    ASSERT_FALSE(document.HasMember("false"));
    ASSERT_TRUE(document.HasMember("test"));
    ASSERT_TRUE(document.HasMember("t"));
    ASSERT_TRUE(document.HasMember("f"));
    ASSERT_TRUE(document["test"].IsString());
    EXPECT_EQ(document["test"], "row");
}
