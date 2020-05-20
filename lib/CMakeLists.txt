#configure directories
set (LIB_MODULE_PATH "${PROJECT_SOURCE_DIR}/lib")

# -------------------------------------------------------------------------
# catch

#configure directories
set (CATCH_MODULE_PATH "${LIB_MODULE_PATH}/Catch")
set (CATCH_INCLUDE_PATH "${CATCH_MODULE_PATH}/include")

#include custom cmake function
include ( "${CATCH_MODULE_PATH}/contrib/ParseAndAddCatchTests.cmake")

#set variables for tests
set (TEST_LIB_INCLUDE_PATH  ${CATCH_INCLUDE_PATH})

#export vars
set (LIB_INCLUDE_PATH  ${LIB_INCLUDE_PATH} PARENT_SCOPE)
set (TEST_LIB_INCLUDE_PATH  ${TEST_LIB_INCLUDE_PATH} PARENT_SCOPE)

# -------------------------------------------------------------------------
# rapidjson

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/rapidjson/include
)