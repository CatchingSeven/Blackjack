cmake_minimum_required(VERSION 3.30)
project(Blackjack)

set(CMAKE_CXX_STANDARD 14)

add_executable(Blackjack src/main.cpp src/Card.cpp src/Deck.cpp src/Hand.cpp src/Player.cpp src/Game.cpp)
