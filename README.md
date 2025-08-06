# CSE-104 - Computer Programming Assignments

This repository contains assignments for CSE-104 (Computer Programming) course. Below is a comprehensive overview of each assignment along with their requirements.

## Repository Structure

```
📦 CSE-104
├── 📁 Offline1/          # Assignment 1 - Calendar Programs
├── 📁 Offline2/          # Assignment 2 - Image Processing (PPM Files)
├── 📁 2005094_2005108/   # Project - Pacman Game (OpenGL/iGraphics)
├── 📄 Offline1.txt      # Assignment 1 specification link
├── 📄 Offline2.txt      # Assignment 2 specification link
└── 📄 README.md         # This file
```

---

## Assignment 1 (Offline1) - Calendar Programs

**📁 Location:** `Offline1/`  
**📄 Files:** `2005094_1.c`, `2005094_2.c`  
**🔗 Specification:** [Assignment Link](https://docs.google.com/document/d/1z7KB88ZdO9kqCUhUskSoUNqGYbohxRnIYVmYjMJrI8o/edit)

### Overview
This assignment implements calendar-related programs using Zeller's congruence algorithm.

### Program 1: Day of Week Calculator (`2005094_1.c`)
- **Purpose:** Determines the day of the week for any given date
- **Input:** Year, month (1-12), and date
- **Algorithm:** Zeller's congruence formula
- **Output:** Displays the day of the week (e.g., "JANUARY 15, 2024 is MONDAY")

### Program 2: Monthly Calendar Display (`2005094_2.c`)
- **Purpose:** Generates and displays a complete monthly calendar
- **Input:** Year and month (1-12)
- **Features:**
  - Displays month name and year
  - Shows calendar in traditional format with days of week headers
  - Handles different month lengths (28/29, 30, 31 days)
  - Proper date alignment based on starting day of month

### Requirements
- **Language:** C
- **Compiler:** Any standard C compiler (GCC recommended)
- **Dependencies:** Standard C libraries (`stdio.h`)
- **Algorithm:** Zeller's congruence for day calculation

### Key Features
- Accurate date calculations for any year (handles leap years)
- User-friendly input/output format
- Modular functions for date validation and day calculation

---

## Assignment 2 (Offline2) - Image Processing

**📁 Location:** `Offline2/`  
**📄 Files:** `main.c`, `utils.h`, `DennisRitchie.ppm`, `toy.ppm`  
**🔗 Specification:** [Assignment Link](https://drive.google.com/file/d/16fwesEijc0nCpcqOCuMmbDUToOX2Gx_0/preview)

### Overview
This assignment focuses on PPM (Portable Pixmap) image file processing and steganography - extracting hidden images from the Least Significant Bits (LSB) of the blue channel.

### Core Components

#### Data Structures (`utils.h`)
```c
typedef struct Color {
    int R, G, B;  // RGB color values
} Color;

typedef struct Image {
    Color **image;  // 2D array of pixels
    int rows, cols; // Image dimensions
} Image;
```

#### Required Functions (`main.c`)
1. **`Image *read_PPM(char *filename)`**
   - Opens and reads PPM files
   - Constructs Image objects
   - Uses: `fopen()`, `fscanf()`, `fclose()`

2. **`void write_PPM(Image *image, char *filename)`**
   - Writes Image objects to PPM format
   - Saves processed images to disk

3. **`void free_image(Image *image)`**
   - Memory management for Image objects
   - Frees all allocated memory including pixel arrays

4. **`Color *evaluate_one_pixel(Image *image, int row, int col)`**
   - Extracts LSB from blue channel of specified pixel
   - Core steganography function

5. **`Image *get_secret_image(Image *image)`**
   - Constructs hidden image from LSB data
   - Calls `evaluate_one_pixel()` for each pixel

### Requirements
- **Language:** C
- **Input Files:** PPM format images (`DennisRitchie.ppm`, `toy.ppm`)
- **Dependencies:** Standard C libraries (`stdio.h`, `stdlib.h`, `inttypes.h`, `string.h`)
- **Memory Management:** Proper allocation and deallocation of dynamic memory
- **File I/O:** Binary file reading/writing for image data

### Key Concepts
- **Steganography:** Hidden data extraction using LSB technique
- **PPM Format:** Understanding of image file structure
- **Dynamic Memory:** 2D array allocation for pixel data
- **Bit Manipulation:** LSB extraction from color values

---

## Project - Pacman Game (Attack on Titan Theme)

**📁 Location:** `2005094_2005108/`  
**📄 Main File:** `pacman.cpp`  
**🎮 Framework:** iGraphics (OpenGL wrapper)

### Overview
A complete Pacman-style game with Attack on Titan anime theme, featuring custom graphics, sound effects, and multiple game modes.

### Game Features

#### Core Gameplay
- **Maze Navigation:** 17x17 grid-based maze system
- **Character Control:** Arrow key movement with collision detection
- **Scoring System:** Points for collecting items, bonuses for special items
- **Lives System:** 3 lives with respawn mechanism
- **Enemy AI:** 4 different titan enemies with unique movement patterns

#### Visual Elements
- **Custom Graphics:** Attack on Titan themed sprites
  - Pacman: Various character forms (erwin.bmp, eren.bmp, etc.)
  - Enemies: Titan sprites (beast.bmp, colossal.bmp, etc.)
  - Mazes: Three wall themes (Wall Sina, Wall Maria, Wall Rose)
- **Animations:** Character movement and eating animations
- **UI Elements:** Score display, life counter, pause screen

#### Audio System
- **Sound Effects:** Eating sounds (`eatpoint.wav`, `eatmusic.wav`)
- **Background Music:** `music2.wav`
- **Music Toggle:** On/off controls for audio

#### Game Modes & Screens
1. **Title Screen:** Main menu with game options
2. **Maze Selection:** Choose from 3 different maze themes
3. **Gameplay:** Main game with pause/resume functionality
4. **High Score:** Score tracking and leaderboard
5. **Instructions:** Game controls and rules
6. **Game Over:** Final score display and restart option

### Technical Implementation

#### Framework: iGraphics
- **Graphics Library:** Custom OpenGL wrapper
- **Event Handling:** Keyboard, mouse, and timer events
- **Image Loading:** BMP file support for sprites
- **Audio Support:** WAV file playback

#### Key Components
```cpp
typedef struct titan {
    int row, column;  // Enemy positions
} titan;

// Game state variables
int maze[17][17];     // Maze layout
int pacCellx, pacCelly; // Player position
int life, total, page; // Game statistics
```

#### Core Functions
- **`drawmaze()`:** Renders maze with appropriate theme
- **`ghostrun()`:** AI movement for enemies
- **`eating()`:** Collision detection and scoring
- **`dead()`:** Life management and game over detection
- **Score management:** File I/O for high score persistence

### Requirements

#### Development Environment
- **Language:** C++ 
- **Graphics:** OpenGL with iGraphics framework
- **Compiler:** Code::Blocks project included (`IGraphics.cbp`)
- **Platform:** Windows (GLUT/OpenGL libraries included)

#### Dependencies
- **Graphics Libraries:**
  - `glut32.dll`, `opengl32.dll`, `glu32.dll`
  - Headers: `GL.H`, `GLU.H`, `glut.h`
- **Audio Libraries:** Windows audio support
- **Image Format:** BMP files for all sprites

#### File Structure
```
2005094_2005108/
├── 🎮 pacman.cpp           # Main game source
├── 📄 iGraphics.h          # Graphics framework
├── 🖼️ *.bmp               # Game sprites and backgrounds
├── 🔊 *.wav               # Sound effects and music
├── 📊 honor_board.txt      # High score storage
├── 📁 bin/Debug/           # Compiled executable
└── 📁 OpenGL/              # Graphics libraries
```

### Game Assets
- **50+ BMP files:** Character sprites, backgrounds, UI elements
- **3 WAV files:** Sound effects and background music
- **3 Maze themes:** Different wall textures and layouts
- **Score persistence:** File-based high score system

---

## Development Setup

### General Requirements
- **C/C++ Compiler:** GCC, MinGW, or Visual Studio
- **IDE:** Code::Blocks, Dev-C++, or Visual Studio (recommended)

### Assignment-Specific Setup

#### Offline1 & Offline2
```bash
gcc -o assignment1 2005094_1.c
gcc -o assignment2 2005094_2.c
gcc -o imageprocessing main.c -lm
```

#### Pacman Project
- **IDE:** Code::Blocks (project file included)
- **Libraries:** OpenGL, GLUT (included in OpenGL folder)
- **Assets:** Ensure all BMP and WAV files are in the same directory

### Running the Programs
1. **Calendar Programs:** Run executables and follow input prompts
2. **Image Processing:** Ensure PPM files are in the correct directory
3. **Pacman Game:** Run executable, use arrow keys for movement, space for pause

---

## Learning Outcomes

### Programming Concepts Covered
- **C Programming:** Functions, structures, file I/O, memory management
- **Algorithm Implementation:** Zeller's congruence, pathfinding, collision detection
- **Graphics Programming:** OpenGL basics, sprite rendering, animation
- **Game Development:** Game loops, state management, user input handling
- **Image Processing:** File formats, bit manipulation, steganography
- **Audio Programming:** Sound effect integration
- **Software Engineering:** Project structure, modular programming

### Skills Developed
- Low-level programming in C/C++
- Mathematical algorithm implementation
- Graphics and game programming
- File I/O and data persistence
- Memory management and optimization
- User interface design
- Project organization and documentation

---

## Academic Information
- **Course:** CSE-104 (Computer Programming)
- **Student IDs:** 2005094, 2005108
- **Submission:** All assignments completed with working implementations
- **Project Status:** Fully functional game with complete feature set