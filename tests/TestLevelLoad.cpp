/* Created by efreyu on 17.05.2020. */

#include <gtest/gtest.h>
#include "../src/Classes/Utilities/JsonLoadManager.h"

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

/*
 * test without constructor
 */
TEST(LevelLoad, FirstLoadLevel) {
    const char* file = "../resources/data/level1.json";
    JsonLoadManager manager1;
    manager1.loadFile(file);
    EXPECT_EQ(manager1.getPath(), file);
    ASSERT_TRUE(manager1.isLoaded());
    ASSERT_TRUE(manager1.getDocument().IsObject());
}

/*
 * test with constructor
 */
TEST(LevelLoad, SecondLoadLevel) {
    const char* file = "../resources/data/level1.json";
    JsonLoadManager manager1(file);
    EXPECT_EQ(manager1.getPath(), file);
    ASSERT_TRUE(manager1.isLoaded());
    ASSERT_TRUE(manager1.getDocument().IsObject());
}

