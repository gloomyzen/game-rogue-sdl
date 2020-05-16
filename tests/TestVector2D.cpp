#include "../src/Classes/DataTypes/Vector2D.h"
#include <gtest/gtest.h>

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

//test constructor
TEST(Vector2D, VectorTest) {
    Vector2D vector1;
    vector1.x = 0.5f;
    vector1.y = 0.5f;
    Vector2D vector2(0.5f, 0.5f);
    EXPECT_EQ(vector1.x, vector2.x);
    EXPECT_EQ(vector1.y, vector2.y);
}