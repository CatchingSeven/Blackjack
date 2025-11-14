cmake_minimum_required(VERSION 3.30)
project(Blackjack)

set(CMAKE_CXX_STANDARD 14)

add_executable(Blackjack main.cpp Card.cpp Deck.cpp Hand.cpp Player.cpp Game.cpp)
