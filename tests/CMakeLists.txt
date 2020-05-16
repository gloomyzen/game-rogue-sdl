cmake_minimum_required(VERSION 3.11)

project(game-rogue-sdl-tests)
include(AddGoogleTest)

add_executable(TestVector2D ./TestVector2D.cpp ../src/Classes/DataTypes/Vector2D.cpp)
add_gtest(TestVector2D)
