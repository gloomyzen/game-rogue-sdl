# Projects Settings
cmake_minimum_required (VERSION 3.1)
project(ROGUE_SDL
        LANGUAGES CXX
        VERSION 1.0.0
)

# The main executable
add_executable(main
        src/Game.cpp
        src/main.cpp
        src/TextureManager.cpp
        src/GameObject.cpp
        src/Map.cpp
        )

set_property(TARGET main PROPERTY CXX_STANDARD 17)
target_compile_options(main PRIVATE -Wall)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE} Debug)
endif()

if(NOT BUILD_TYPE)
    set(BUILD_TYPE ${BUILD_TYPE} "desktop")
endif()

# Detect emscripten is used.
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

    #TODO add Release and Debug mode with some flags
    #string(APPEND CMAKE_CXX_FLAGS " --closure 1")
    #string(APPEND CMAKE_CXX_FLAGS " --js-opts 3")
    #string(APPEND CMAKE_CXX_FLAGS " --llvm-lto 3")
    #string(APPEND CMAKE_CXX_FLAGS " --llvm-opts 3")
    #string(APPEND CMAKE_CXX_FLAGS " -O3")

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


    set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

    find_package(SDL2 REQUIRED)
    find_package(SDL2_image REQUIRED)
    include_directories(${SDL2_INCLUDE_DIRS})
    include_directories(${SDL2_IMAGE_DIRS})

    file(COPY "${CMAKE_SOURCE_DIR}/resources/sprites/"
            DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/resources/sprites)

    target_link_libraries(main ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

endif()
