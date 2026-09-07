# 🎮 Tetris Game

A simple **Tetris game built in C++ using OpenGL and GLUT**.
The project implements the core mechanics of Tetris, including piece movement, rotation, collision detection, line clearing, scoring, game-over detection, and a win condition.

## ✨ Features

* 🎲 Randomly generated Tetris pieces
* 🧱 10 × 20 game board
* 🔄 Piece rotation
* ⬅️ Move pieces left
* ➡️ Move pieces right
* ⬇️ Move pieces down
* 💥 Collision detection
* 🔒 Piece locking
* 🧹 Completed line detection and clearing
* 🏆 Score system
* 🎯 Win condition at **1000 points**
* 💀 Game-over detection when a new piece cannot spawn
* 🖥️ Score displayed directly on the game window
* 🎮 Simple keyboard controls
* 🟦 Includes four pieces:

  * I
  * O
  * T
  * L

## 🛠️ Technologies Used

* **C++**
* **OpenGL**
* **GLUT (OpenGL Utility Toolkit)**

## 📂 Project Structure

```text
Tetris/
│
├── game.h          # Game logic, pieces, movement, collision, scoring
├── main.cpp         # Main program and OpenGL setup
└── README.md        # Project documentation
```

> The exact filenames may vary depending on your project structure.

## 🎮 Controls

| Key            | Action          |
| -------------- | --------------- |
| ⬆️ Up Arrow    | Rotate piece    |
| ⬅️ Left Arrow  | Move left       |
| ➡️ Right Arrow | Move right      |
| ⬇️ Down Arrow  | Move piece down |

## 🧩 Game Pieces

The game currently contains four different pieces.

### I Piece

```text
████
```

Can rotate between horizontal and vertical orientations.

### O Piece

```text
██
██
```

The O piece does not require rotation.

### T Piece

```text
 █
███
```

The T piece has four rotations.

### L Piece

```text
███
█
```

The L piece has four rotations.

## 🏆 Scoring

Every time a complete horizontal line is cleared:

```text
+100 points
```

The player wins when the score reaches:

```text
1000 points
```

A **YOU WIN!** message is displayed when the player reaches the required score.

## 💀 Game Over

The game does not simply wait until the entire board is filled.

Instead, after a piece is locked, a new piece is spawned at the top of the board.

If there is no space for the new piece, the game ends and displays:

```text
GAME OVER
```

After game over, player controls are disabled.

## 🔄 Game Flow

```text
Start Game
    │
    ▼
Generate Random Piece
    │
    ▼
Check Spawn Position
    │
    ├── No Space ──► GAME OVER
    │
    ▼
Move / Rotate Piece
    │
    ▼
Collision Check
    │
    ▼
Piece Cannot Move Down
    │
    ▼
Lock Piece
    │
    ▼
Clear Completed Lines
    │
    ▼
Add Score
    │
    ├── Score >= 1000 ──► YOU WIN!
    │
    ▼
Generate Next Piece
    │
    └──────────────► Repeat
```

## ⚙️ How Collision Detection Works

Before moving or rotating a piece, the game checks the board positions that the piece would occupy.

A position is considered invalid if:

* It goes outside the board boundaries.
* It overlaps an already locked block.

For example, when moving a piece to the left, the game checks the cells immediately to the left of the piece.

If any of those cells contain a locked block, the movement is rejected.

## 🧹 Line Clearing

After a piece is locked, the game checks every row of the board.

If all 10 cells in a row are occupied:

1. The row is removed.
2. Every row above it moves down.
3. The top row is cleared.
4. The score increases by 100.

## 🚀 Installation

### Requirements

You need:

* A C++ compiler
* OpenGL
* GLUT / FreeGLUT
* A development environment such as:

  * Visual Studio
  * Code::Blocks
  * VS Code with the required compiler and libraries

### Linux

On Ubuntu/Debian-based systems, you can install the required OpenGL/GLUT development packages with:

```bash
sudo apt update
sudo apt install g++ freeglut3-dev
```

Then compile the project according to your source filenames.

For example:

```bash
g++ main.cpp -o tetris -lGL -lGLU -lglut
```

Run it with:

```bash
./tetris
```

> Compilation commands may need to be adjusted depending on your project structure and operating system.

## 🖥️ OpenGL Coordinate System

The game board is:

```text
Width  = 10 blocks
Height = 20 blocks
```

Each block has a size of:

```text
50 × 50 pixels
```

Therefore, the game window is:

```text
500 × 1000 pixels
```

## 📚 Learning Objectives

This project was created to practice:

* C++ functions
* Arrays
* Conditional statements
* Loops
* Collision detection
* Game state management
* 2D board representation
* OpenGL rendering
* Keyboard input handling
* Basic game logic
* Object movement and rotation

## 🔮 Possible Future Improvements

Some features that could be added later:

* More Tetris pieces
* Increasing difficulty/speed
* Automatic piece falling
* Pause and resume
* Restart button
* Next-piece preview
* Hold-piece functionality
* Ghost piece
* Better rotation system
* Sound effects
* Background music
* Main menu
* High-score system
* Improved graphics and animations

## 👨‍💻 Author

**Haris**

A C++ OpenGL project created as a learning project to understand basic game development and graphics programming.
