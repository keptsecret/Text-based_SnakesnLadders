cmake_minimum_required(VERSION 3.16)

project(TextbasedSnakesnLadders VERSION 0.1.2
                                LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)

add_executable(game tester.cpp Board.cpp Ladder.cpp Snake.cpp Player.cpp)