cmake_minimum_required(VERSION 3.21)
project(MyGame LANGUAGES CXX)

# C++ version
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# include engine
add_subdirectory(libs/yak)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

# add our source
add_executable(MyGame src/main.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "GameName")
target_link_libraries(MyGame PRIVATE yak sfml-graphics)
target_compile_features(MyGame PRIVATE cxx_std_17)

if(WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET MyGame POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:MyGame> $<TARGET_FILE_DIR:MyGame> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS MyGame)