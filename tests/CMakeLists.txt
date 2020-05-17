include(AddGoogleTest)

add_executable(TestVector2D ./TestVector2D.cpp ../src/Classes/DataTypes/Vector2D.cpp)
add_gtest(TestVector2D)

add_executable(TestJsonDeps ./TestJsonDeps.cpp)
add_gtest(TestJsonDeps)