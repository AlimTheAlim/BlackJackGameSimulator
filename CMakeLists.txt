# required to set the cmake version
cmake_minimum_required(VERSION 3.14)
# a project name is required
project(blackjack)


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# creating the executable, the path to each cpp file is relitive to where this CMakeLists.txt file is located
add_executable(blackjack ./src/Deck.cpp ./src/Card.cpp ./src/player.cpp ./app/game.cpp)