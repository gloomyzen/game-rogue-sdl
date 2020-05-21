include(AddGoogleTest)

function(INIT_TEST ARG_TARGET)
    add_executable(${ARG_TARGET} ${ARGN})
    set_property(TARGET ${ARG_TARGET} PROPERTY CXX_STANDARD 17)
    target_compile_options(${ARG_TARGET} PRIVATE -Wall)
    add_gtest(${ARG_TARGET})
endfunction()

init_test(TestVector2D ./TestVector2D.cpp ../src/Classes/DataTypes/Vector2D.cpp)
init_test(TestJsonDeps ./TestJsonDeps.cpp)
init_test(TestLevelLoad ./TestLevelLoad.cpp ../src/Classes/Utilities/LoadManager.cpp ../src/Classes/Utilities/JsonLoadManager.cpp)