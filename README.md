# **Reversi Board**

This project implements the core components of a console-based Reversi game (also known as Reversi).

The goal of this exercise is to apply object-oriented programming principles in C++ by separating game logic and user interface into distinct classes, and by providing proper UML diagrams and Doxygen documentation.

## 🎯 **Objective**

Develop a small console application that:

- Represents a Reversi game board.

- Validates and executes player moves according to the game rules.

- Displays the board state in the console.

- Is fully documented using Doxygen.

## 🧩 **Implemented Classes**
### **1. ReversiBoard**

**Represents the internal state of the game board.**

Responsibilities:

- Store the state of each field (empty, player 1, player 2)

- Provide a method to query the state of any field

- Provide a method to place a piece on the board

- Validate moves according to Reversi rules

- Flip opponent pieces when a valid move is made

Technical requirements:

- Use an enum to represent field states

- Ensure move validation before modifying the board

- Encapsulate board data properly

### **2. ReversiConsoleView**

**Responsible for displaying the board in the console.**

Responsibilities:

- Receive a pointer to a ReversiBoard instance via constructor

- Access board state through public methods

- Print a formatted representation of the board

- This class strictly separates presentation logic from game logic.

## 🔁 **Program Flow (main)**

The main function contains a simple game loop:

- Ask the user where to place the next piece

- Call the board’s method to perform the move

- Print the updated board

- Repeat until termination condition

## 📚 **Documentation**

The project includes:

- Full Doxygen-style documentation

- Generated HTML documentation

Proper descriptions of:

- Classes

- Methods

- Parameters

- Return values

- Responsibilities

- The generated documentation can be built using the provided .doxyfile configuration.

## 🧠 **Learning Goals**
- Object-Oriented Design (OOP)

- Separation of concerns

- Enumeration types

- Rule-based game logic

- UML modeling

- Professional documentation with Doxygen
