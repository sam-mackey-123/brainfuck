cmake_minimum_required(VERSION 3.15)

project(brainfuck VERSION 1.0)

# set(SOURCES
#     Window.cpp
#     Game.cpp
#     Paddle.cpp
#     Object.cpp
#     Ball.cpp
# )

# set(HEADERS
#     Window.h
#     Game.h
#     Paddle.h
#     Object.h
#     Ball.h
# )

add_executable(ccbf main.cpp)

target_compile_features(ccbf PUBLIC cxx_std_17)

find_package(Catch2 3 REQUIRED)

add_executable(tests test.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
