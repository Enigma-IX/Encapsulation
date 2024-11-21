
# Encapsulation

## Project Overview

Welcome to **Encapsulation**, a C++ project aimed at mastering the fundamentals of object-oriented programming, specifically encapsulation, while gaining hands-on experience with low-level graphics libraries like SDL and Raylib. This project is a practical exercise in designing and implementing a 2D scene featuring bouncing circles using encapsulated libraries.

---

## Table of Contents

1. [Project Details](#project-details)
2. [Getting Started](#getting-started)
3. [Requirements](#requirements)
4. [Features](#features)
5. [Usage](#usage)

---

## Project Details

- **Project Name**: Encapsulation  
- **Project ID**: 03  
- **Timeline**: November 18, 2024 - November 22, 2024  
- **Class**: GTECH-4  

### Context

The project focuses on:
- Understanding encapsulation principles in C++.
- Wrapping and abstracting functionalities of SDL and Raylib.
- Designing a dynamic 2D scene with bouncing circles.

---

## Getting Started

### Prerequisites

1. **C++ Compiler**: A modern C++ compiler (e.g., g++, clang++).
2. **Graphics Libraries**:
   - SDL (2.x or higher)
   - Raylib (4.x or higher)
3. **Development Environment**: Any IDE or text editor supporting C++.

### Installation

Clone the repository and navigate to the project directory:

```bash
git clone https://github.com/yourusername/encapsulation.git
cd encapsulation
```

### Build

To build the project with SDL or Raylib encapsulation:

```bash
# Compile with SDL
make USE_SDL=1

# Compile with Raylib
make USE_RAYLIB=1
```

---

## Requirements

### Core Encapsulation

1. **Abstract Classes**:
   - `Window`: Virtual functions for managing window operations (initialize, draw, etc.).
   - `Sprite`: Virtual functions for loading and managing sprite data.

2. **Library-Specific Implementations**:
   - SDL and Raylib-based classes inheriting from `Window` and `Sprite`.

3. **No Global Dependencies**:
   - All library-specific functionality must be encapsulated within their respective classes.

### 2D Scene Features

- Randomly generated circles moving in random directions.
- Circles bounce off the window edges.
- Display a real-time FPS counter.

---

## Features

1. **Modular Encapsulation**:
   - Choose SDL or Raylib at compile-time or via runtime arguments.
2. **Dynamic Scene**:
   - Circles bounce seamlessly within the window.
3. **FPS Counter**:
   - Real-time performance feedback.
4. **Game Modes**:
   - Multiple game modes.

---

## Usage

Run the program with the desired encapsulation:

```bash
# Exemples:

# Use SDL encapsulation
./encapsulation -SDL

# Use Raylib encapsulation
./encapsulation -Raylib

# Use Raylib encapsulation and Launch Pong game mode
./encapsulation -Raylib -Pong
```

Arguments:
- `-SDL`: Use SDL for graphics rendering.
- `-Raylib`: Use Raylib for graphics rendering.

- `-Demo`: Launch the Demo.
- `-Pong`: Launch the Pong Game.
- `-Brick`: Launch the Brick Game.

---

**Team Members**:
- [Enigma-IX](https://github.com/Enigma-IX)
- [Liz](https://github.com/liza-harcheb)

---

