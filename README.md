\# Pixel Lab



A small 2D game programming project built with \*\*C++17\*\* and \*\*SDL3\*\*.



Pixel Lab is a learning project where I explore the fundamentals of 2D game development, including rendering, keyboard input, movement, collision detection, and game loops.



\## Features



\- Window creation and rendering using SDL3

\- Keyboard-controlled player movement

\- Frame-rate-independent movement using delta time

\- Window boundary detection

\- Collectible objects

\- Rectangle-based collision detection

\- Random collectible respawning

\- Collection counter



\## Technologies



\- C++17

\- SDL3

\- CMake

\- Git



\## Controls



| Key | Action |

|---|---|

| Arrow keys | Move the player |

| Close button | Exit the game |



\## Requirements



\- Windows

\- CMake 3.24 or newer

\- A compatible C++17 compiler

\- Git



\## Building and Running



Clone the repository and its SDL3 submodule:



```bash

git clone --recurse-submodules YOUR\_REPOSITORY\_URL

cd pixel-lab

```



Configure the project:



```bash

cmake -S . -B build

```



Build the project:



```bash

cmake --build build --config Debug

```



Run the game:



```bash

./build/Debug/pixel\_lab.exe

```



\## Project Structure



```text

pixel-lab/

├── CMakeLists.txt

├── README.md

├── .gitignore

├── src/

│   └── main.cpp

└── external/

&#x20;   └── SDL/

```



\## Learning Goals



This project is part of my journey toward understanding C++ game development and contributing to open-source graphics and gaming projects.



It serves as a practical exploration of game loops, rendering, input handling, object movement, and collision detection.



\## Future Improvements



\- Display the score inside the game window

\- Prevent collectibles from spawning on top of the player

\- Improve code organization by separating game logic into functions

\- Add more game objects and mechanics

