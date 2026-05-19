# Blackjack-SFML

This project began during a university break. My primary motivation was to further develop my understanding of Object-Oriented Programming (OOP) concepts and to gain more practical experience writing C++. It has evolved from its initial console-based origins into a fully interactive, graphical Blackjack game built using the Simple Fast Multimedia Library (SFML).

## Project Status: Playable & Expanding
The core game is fully functional. The application runs entirely within an SFML window, starting with a fully implemented Main Menu. Standard rounds of Blackjack (hitting, standing, and dealer logic) are completely playable, with the gameplay loop driven by an internal enum-based state machine that handles player turns, dealer turns, and round resolution.

While the game works, it is currently in an active development phase. The initial front-end code became quite messy as I was learning SFML, so a major ongoing priority is refactoring the codebase to cleanly decouple the game logic from the rendering layer. Simultaneously, I am expanding the game to include more complex mechanics and meta-features.

## Tech Stack & Compatibility
*   **Language:** C++17
*   **Graphics/Windowing:** SFML 2.5 (Graphics, Window, System, and Audio modules)
*   **Build System:** CMake 3.30+
*   **OS:** Developed and tested on Windows.

## How to Use This Project

There are two ways to interact with this project: playing the current working build or compiling the source code yourself.

### 1. Playing the Game (No Compilation Required)
While the game is still in active development, the core gameplay loop is functional. You can run it without needing C++ or CMake:
*   Download the project folder.
*   Ensure all provided SFML `.dll` files and the asset folders remain in the exact same directory as the executable.
*   Run `Blackjack.exe`.

### 2. Building from Source (For Developers)
To compile this locally to edit the source code, you need a C++17 compatible compiler and SFML 2.5 installed on your system.

**Important for CMake:** Inside the `CMakeLists.txt`, the `SFML_DIR` variable is hardcoded to my local environment directory. You must update this path to point to your own SFML installation before running CMake.
```cmake
# Example of what to change in CMakeLists.txt:
set(SFML_DIR "C:/Path/To/Your/SFML/lib/cmake/SFML")
```
## Credits
*   **Code & Architecture:** CatchingSeven
*   **Visual Assets:** The card graphics used in this build are free/open-source assets. I originally sourced them during the early prototyping phase and am currently tracking down the original creator's page to provide full and proper attribution. If you happen to recognize these specific assets, please open an issue or reach out so I can update this section immediately!

## License
This project is licensed under the MIT License. 

You are free to use, modify, and distribute this software, provided that the original copyright notice and this permission notice are included in all copies or substantial portions of the software. See the `LICENSE` file for more details.
