#include(AddGoogleTest)
#
#add_executable(TestVector2D ./TestVector2D.cpp ../src/Classes/DataTypes/Vector2D.cpp)
#add_gtest(TestVector2D)
#
#add_executable(TestJsonDeps ./TestJsonDeps.cpp)
#add_gtest(TestJsonDeps)
#
#add_executable(TestLevelLoad ./TestLevelLoad.cpp ../src/Classes/Utilities/LoadManager.cpp ../src/Classes/Utilities/JsonLoadManager.cpp)
#add_gtest(TestLevelLoad)

# CMake build : library tests

#configure variables
set (TEST_APP_NAME "${PROJECT_NAME}_Test")

#configure directories
set(TEST_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}")

#configure test directories
set(TEST_SRC_PATH  "${TEST_MODULE_PATH}/src")

##set includes
include_directories(${LIB_INCLUDE_PATH} ${TEST_LIB_INCLUDE_PATH})

#set test sources
file(GLOB TEST_SOURCE_FILES "${TEST_SRC_PATH}/*.cpp")

#set target executable
add_executable(${TEST_APP_NAME} ${TEST_SOURCE_FILES})

#add the library
#target_link_libraries (${TEST_APP_NAME} ${LIB_NAME} Threads::Threads)

#setup standards
set_property(TARGET ${TEST_APP_NAME} PROPERTY CXX_STANDARD 17)
target_compile_options(${TEST_APP_NAME} PRIVATE -Wall)

# Turn on CMake testing capabilities
enable_testing()

#parse catch tests
#message(FATAL_ERROR ${TEST_SOURCE_FILES})
ParseAndAddCatchTests(${TEST_APP_NAME})