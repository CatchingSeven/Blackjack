cmake_minimum_required(VERSION 3.30)
project(Blackjack)

set(CMAKE_CXX_STANDARD 17)
set(SFML_DIR "C:/Libraries/SFML-2.6.2/lib/cmake/SFML")


find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
add_executable(Blackjack src/main.cpp src/Card.cpp src/Deck.cpp src/Hand.cpp src/Player.cpp src/Game.cpp src/GameApp.cpp src/Settings.cpp)
target_link_libraries(Blackjack sfml-graphics sfml-window sfml-system sfml-audio)