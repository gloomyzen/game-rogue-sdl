#------------------------------------------------------------------------------
# General Projects Settings
#------------------------------------------------------------------------------
cmake_minimum_required (VERSION 3.11)
project(ROGUE_SDL
        LANGUAGES CXX
)

#------------------------------------------------------------------------------
# The main executable
#------------------------------------------------------------------------------
add_executable(main
        src/Classes/Game.cpp
        src/main.cpp
        src/Classes/TextureManager.cpp
        src/Classes/GameObjects/GameObject.cpp
#        src/Scene.cpp
        src/Classes/DataTypes/Vector2D.cpp
        src/Classes/ECS/Collision.cpp
        src/Classes/ECS/ECS.cpp
        )

set_property(TARGET main PROPERTY CXX_STANDARD 17)
target_compile_options(main PRIVATE -Wall)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE} Debug)
endif()

if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D__DEBUG__")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D__RELEASE__")
endif()

if(NOT BUILD_TYPE)
    set(BUILD_TYPE ${BUILD_TYPE} "desktop")
endif()

include(ExternalProject)
find_package(Git)
if(NOT GIT_FOUND)
    message(FATAL_ERROR "Git not found!")
endif()

#------------------------------------------------------------------------------
# General dependencies.
#------------------------------------------------------------------------------
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/rapidjson/include
)

#------------------------------------------------------------------------------
# Detect emscripten is used.
#------------------------------------------------------------------------------
if(${BUILD_TYPE} STREQUAL webassembly)

    set(CMAKE_C_COMPILER "emcc")
    set(CMAKE_CXX_COMPILER "em++")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D__EMSCRIPTEN__")

    set_target_properties(main PROPERTIES OUTPUT_NAME "main.js")

#    string(APPEND CMAKE_CXX_FLAGS " -s DEMANGLE_SUPPORT=1")
#    string(APPEND CMAKE_CXX_FLAGS " -s DISABLE_EXCEPTION_CATCHING=2")
    # -s ASSERTIONS=2 - a vital tool to figure out where things are going wrong.
    # Even in ‘production’ builds I’ll keep this at 1 despite the significant performance overhead.
#    string(APPEND CMAKE_CXX_FLAGS " -s ASSERTIONS=2")
    string(APPEND CMAKE_CXX_FLAGS " -s USE_WEBGL2=1")
    string(APPEND CMAKE_CXX_FLAGS " -s USE_SDL=2")
    string(APPEND CMAKE_CXX_FLAGS " -s USE_SDL_IMAGE=2")
    string(APPEND CMAKE_CXX_FLAGS " -s SDL2_IMAGE_FORMATS=[\"png\"]")
    string(APPEND CMAKE_CXX_FLAGS " -s WASM=1")
    string(APPEND CMAKE_CXX_FLAGS " -Wall")
    string(APPEND CMAKE_CXX_FLAGS " -s NO_EXIT_RUNTIME=1")
    string(APPEND CMAKE_CXX_FLAGS " -s EXPORTED_FUNCTIONS=\"['_main', '_window_resize']\"")
    string(APPEND CMAKE_CXX_FLAGS " -s EXTRA_EXPORTED_RUNTIME_METHODS=\"['cwrap', 'ccall']\"")

    #TODO add Release and Debug mode with some flags
    #string(APPEND CMAKE_CXX_FLAGS " --closure 1")
    #string(APPEND CMAKE_CXX_FLAGS " --js-opts 3")
    #string(APPEND CMAKE_CXX_FLAGS " --llvm-lto 3")
    #string(APPEND CMAKE_CXX_FLAGS " --llvm-opts 3")
    #string(APPEND CMAKE_CXX_FLAGS " -O3")

    # Debug bar.
    if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
        file(READ ${CMAKE_CURRENT_SOURCE_DIR}/resources/stub/index-debug-section.html debug-bar)
    endif()

    # Copy the index.html file.
    configure_file(
            ${CMAKE_CURRENT_SOURCE_DIR}/resources/stub/index.html
            ${CMAKE_CURRENT_BINARY_DIR}/index.html
    )
    # Copy the style.css file.
    configure_file(
            ${CMAKE_CURRENT_SOURCE_DIR}/resources/stub/style.css
            ${CMAKE_CURRENT_BINARY_DIR}/style.css
    )
    # Copy the favicon.
    configure_file(
            ${CMAKE_CURRENT_SOURCE_DIR}/resources/stub/favicon.ico
            ${CMAKE_CURRENT_BINARY_DIR}/favicon.ico
    )

    # Allow the resource directories to be fetched by the web browser.
    file(GLOB assets_files "${CMAKE_SOURCE_DIR}/resources/sprites/*" "${CMAKE_SOURCE_DIR}/resources/font/*.ttf")
    foreach(file ${assets_files})
        file(RELATIVE_PATH relative_file ${CMAKE_SOURCE_DIR} ${file})
        string(APPEND CMAKE_CXX_FLAGS " --preload-file ${file}@/${relative_file}")
        message(STATUS CMAKE_CXX_FLAGS " --preload-file ${file}@/${relative_file}")
    endforeach()

else() # Not Web

    file(COPY "${CMAKE_SOURCE_DIR}/resources/sprites/"
            DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/resources/sprites)

    if (APPLE)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D__APPLE__")
        if(NOT EXISTS "${CMAKE_SOURCE_DIR}/lib/macOS/SDL2.framework")
                message("Downloading SDL2 frameworks")
                execute_process(
                        COMMAND "chmod +x ${CMAKE_SOURCE_DIR}/lib/macOS/install.sh"
                        WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/lib/macOS")
                execute_process(
                        COMMAND "${CMAKE_SOURCE_DIR}/lib/macOS/install.sh"
                        WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/lib/macOS")
        endif()
        set(SDL_INCLUDE_DIR "")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -F ${CMAKE_SOURCE_DIR}/lib/macOS")
        #TODO for future static linking
        #set(CMAKE_EXE_LINKER_FLAGS "-Wl,-F${CMAKE_SOURCE_DIR}/lib/macOS -Wl,-rpath ${CMAKE_SOURCE_DIR}/lib/macOS -framework Cocoa")
        #set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}")
        set(SDL_LIBRARY
        "-framework SDL2"
        "-framework SDL2_ttf"
        "-framework SDL2_mixer"
        "-framework SDL2_image"
        )
        set(SDL_EXPORT_LIBRARIES
        "${CMAKE_SOURCE_DIR}/lib/macOS/SDL2.framework"
        "${CMAKE_SOURCE_DIR}/lib/macOS/SDL2_ttf.framework"
        "${CMAKE_SOURCE_DIR}/lib/macOS/SDL2_mixer.framework"
        "${CMAKE_SOURCE_DIR}/lib/macOS/SDL2_image.framework"
        )
        mark_as_advanced(SDL_INCLUDE_DIR SDL_LIBRARY)
        target_link_libraries(main ${SDL_LIBRARY})

        include_directories(${SDL_INCLUDE_DIR})

    endif()

    find_package(SDL2 REQUIRED)
    find_package(SDL2_image REQUIRED)

    include_directories(${SDL2_INCLUDE_DIR})
    include_directories(${SDL2_IMAGE_INCLUDE_DIR})

    target_link_libraries(main ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

#------------------------------------------------------------------------------
# Tests section
#------------------------------------------------------------------------------

enable_testing()
add_subdirectory(tests)

endif()