**C++ Library Management System**

![Language](https://img.shields.io/badge/Language-C++-blue)
![Level](https://img.shields.io/badge/Level-Beginner-green)
![Focus](https://img.shields.io/badge/Focus-OOP%20%7C%20Object%20Copying-orange)

A console-based Library Management System built in C++.

This project was created to practice object-oriented design, object copying behavior, and state management without using dynamic memory.

--------------------------------------------------------------------

**What This Project Covers**

- Class design and encapsulation
- Default and parameterized constructors
- Passing objects by const reference
- Returning objects from functions
- Object assignment and copying
- Managing internal object state (borrowed / available)
- Basic search and maximum-value logic

--------------------------------------------------------------------

Structure:

**Book Class**
Represents a single book in the library.

Private members:
- Title
- Author
- Number of pages
- Borrowed state

Public functionality:
- Borrow / return logic
- Getter functions
- Print function

--------------------------------------------------------------------

**Library Class**
Manages a fixed-size collection of books stored as objects (not pointers).

Features:
- Add books
- Borrow by title
- Return by title
- List all books
- Find the largest book (by pages)
- Basic empty-state handling

--------------------------------------------------------------------

**Why This Version Uses Objects Instead of Pointers**

Unlike the previous Garage project, this system stores books directly in an array.  

This was done intentionally in order to observe how object copying and assignment work in C++ when passing and returning objects.

--------------------------------------------------------------------
