# OOP EX6 - Click the Bubble

A simple bubble-clicking game made with C++ and Raylib.

## Gameplay
- Multiple bubbles appear on the screen.
- Click bubbles to gain score.
- Smaller bubbles give higher score.
- The game lasts 30 seconds.
- When time is up, the final score is shown.

## Features
- Implemented with at least one class: `Bubble`
- Encapsulation is used by keeping bubble data private and accessing it through member functions
- Score system
- Timer
- Multiple bubbles

## Project Structure
- `include/Bubble.h` : Bubble class declaration
- `src/Bubble.cpp` : Bubble class implementation
- `src/main.cpp` : main game loop
- `resources/` : assets if needed

## Build
In the project root directory:

    cmake -B build
    cmake --build build

## Run
On Windows:

    .\build\OOP_Raylib_Lab.exe

## Author
Max Chen