# Blackjack

## Overview

Blackjack is a single-player Blackjack game developed in C++ using the Simple and Fast Multimedia Library (SFML). I originally started working on this project during a university break, primarily as a means of further developing my understanding of Object-Oriented Programming (OOP) and becoming more comfortable programming in C++.

Initially, the project was developed as a simple console-based application, with most of my attention being directed towards implementing the underlying game logic and applying OOP concepts in practice. However, as development progressed, I decided to expand the project into a graphical application using SFML. Having never worked with a graphical library before, this presented an opportunity to learn something new while continuing to develop my existing programming skills.

Although the project is no longer under active development, I've decided to keep it around as a demonstration of what I learned throughout the development process.

## Features and Implementation

The application implements the fundamental mechanics of Blackjack, allowing the player to compete against a computer-controlled dealer.

The current implementation includes:

- A graphical interface developed using SFML.
- A main menu allowing the player to start a game.
- The ability to hit or stand during a round.
- Automated dealer behaviour, with the dealer drawing cards until reaching a hand value of at least 17.
- Card shuffling, dealing and hand-value calculations.
- Round outcomes and the ability to start another round.

The application makes use of several classes to represent the different components of the game, including cards, decks, hands and players. This allowed me to apply concepts such as encapsulation and abstraction, while keeping the underlying game logic seperate from the graphical interface.

Additionally, the application uses an enum-based state machine to manage the progression of the game, including the main menu, player and dealer turns, and the conclusion of each round.

## Development and Learning

One of the main reasons I began working on this project was to gain more practical experience with C++ and OOP outside of university coursework. While I had already gained some experience with the language, I wanted to become more comfortable developing applications consisting of multiple classes, and understanding how these classes should interact with one another.

The transition from a console-based application to a graphical interface was probably the most challenging aspect of development. Having never used SFML before, I had to familiarise myself with concepts such as rendering, textures, sprites, event handling and managing the application window.

As I continued developing the graphical interface, I also began to encounter problems with how I had structured the application. In particular, the code responsible for rendering and handling the game became increasingly difficult to maintain as I introduced additional functionality.

Looking back at the code now, I can definitely see where I could have approached certain things differently. For example, some of the functionality within the `GameApp` class would have been better implemented using smaller, more specialised components rather than having one class responsible for so much of the application.

Nevertheless, working through these problems helped me develop a better understanding of software design, particularly the importance of separating responsibilities between classes and considering maintainability during development.

## Technologies Used

- **Programming Language:** C++17
- **Graphical Library:** SFML 2.6.2
- **Build System:** CMake 3.30+
- **Operating System:** Windows

**Compatibility:** This project was developed specifically for Windows, and is not intended to run on Linux or macOS.

## Running the Application

A compiled Windows executable is included in the repository, so you do not need to compile the source code yourself to run the application.

To run the game:

1. Download or clone the repository.
2. Navigate to the `cmake-build-debug` directory.
3. Run `Blackjack.exe`.

The executable requires the included SFML DLL files and graphical assets to function correctly. Make sure the existing directory structure is preserved, otherwise the application may not be able to locate the required files.

### Controls

| Key | Function |
|---|---|
| Mouse | Select Play from the main menu |
| H | Hit |
| S | Stand |
| Y | Start another round |
| Q | Return to the main menu after a round |

## Building from Source

If you would prefer to compile the application yourself, you will need a C++17 compatible compiler, CMake and SFML installed on your system.

The project was developed using SFML 2.6.2, and its CMake configuration requires SFML 2.5 or later.

Before compiling, you will need to configure the `SFML_DIR` variable in `CMakeLists.txt` to point towards your own SFML installation.

For example:

```cmake
set(SFML_DIR "C:/path/to/your/SFML/lib/cmake/SFML")
```

Replace the example directory with the actual location of SFML on your system.

Once this has been configured, the project can be built using CMake.

## Project Status

This project is no longer under active development.

While the core gameplay has been implemented, certain aspects of the application remain unfinished, particularly the settings functionality. There are also several areas of the codebase that could benefit from refactoring, especially the graphical interface.

I've decided to leave the project in its current state, rather than continue developing it, as I think it serves as a useful record of my programming experience at the time.

**Note:** Yeah, I know its pretty rough around the edges. Some of the code is genuinely painful to look at now, particularly the graphical stuff. But I was still figuring things out as I went along, and I think that becomes painfully obvious in certain parts of the code.

## Credits

**Programming and application development:** CatchingSeven

The card graphics used in the application were obtained from freely available assets during the early stages of development. Unfortunately, I haven't been able to find the original source of these assets to provide proper attribution.

If you happen to recognise them, feel free to let me know.

## License

This project is licensed under the MIT License.

You are free to use, modify and distribute the software under the conditions outlined in the [LICENSE](LICENSE) file.
