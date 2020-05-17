#include "../src/Classes/DataTypes/Vector2D.h"
#include <gtest/gtest.h>

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(Vector2D, VectorConstructorTest) {
    Vector2D vector1;
    vector1.x = 0.5f;
    vector1.y = 0.5f;
    Vector2D vector2(0.5f, 0.5f);
    EXPECT_EQ(vector1.x, vector2.x);
    EXPECT_EQ(vector1.y, vector2.y);
}

TEST(Vector2D, VectorZeroTest) {
    Vector2D vector1(0, 0);
    Vector2D vector2;
    vector2.Zero();
    EXPECT_EQ(vector1.x ,vector2.x);
    EXPECT_EQ(vector1.y ,vector2.y);
}

TEST(Vector2D, VectorAddTest) {
    Vector2D vector1(0, 0);
    Vector2D vectorExpect = vector1;
    Vector2D vector2(264, 255);
    vector1.Add(vector2);
    EXPECT_EQ(vector1.x ,vectorExpect.x + vector2.x);
    EXPECT_EQ(vector1.y ,vectorExpect.y + vector2.y);
}