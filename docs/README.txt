Here is the text fully formatted with Markdown so it renders cleanly with proper headings, lists, and code blocks on GitHub. You can copy this exactly as it is and paste it into your `README.md` file.

***

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

## Build Instructions
To compile this locally, you need a C++17 compatible compiler and SFML installed on your system.

**Important:** Inside the `CMakeLists.txt`, the `SFML_DIR` variable is hardcoded to my local environment directory. You must update this path to point to your own SFML installation before running CMake.

```cmake
# Example of what to change in CMakeLists.txt:
set(SFML_DIR "C:/Path/To/Your/SFML/lib/cmake/SFML")
```

## Development Roadmap
The current objective is to upgrade the working game into a polished, feature-complete application.

### Immediate Priorities
*   **Refactoring:** Cleaning up the front-end architecture and properly separating the Model (game logic) from the View (SFML rendering).
*   **Settings & Dynamic UI:** Currently building out the Settings menu, while upgrading the UI to support dynamic window scaling and responsive card placement (replacing hardcoded coordinates).

### Future Goals
*   **Extended State Management:** Expanding the existing state machine to handle pausing and seamless transitions between all UI layers.
*   **Feature Expansion:** Implementing betting logic, doubling down, and splitting hands.
*   **Persistence:** Saving player progress, high scores, and bankrolls between sessions.
*   **Visual Polish:** Adding custom backgrounds, better graphics, and card-dealing animations.

## Credits
The visual assets used for the cards are open-source. I originally downloaded them from a game art website, but I have misplaced the exact link. I am currently trying to track down the source to provide proper attribution in a future update.
