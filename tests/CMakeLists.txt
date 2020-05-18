include(AddGoogleTest)

add_executable(TestVector2D ./TestVector2D.cpp ../src/Classes/DataTypes/Vector2D.cpp)
add_gtest(TestVector2D)

add_executable(TestJsonDeps ./TestJsonDeps.cpp)
add_gtest(TestJsonDeps)

add_executable(TestLevelLoad ./TestLevelLoad.cpp ../src/Classes/Utilities/JsonLoadManager.cpp)
add_gtest(TestLevelLoad)
