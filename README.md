# Task 1: Core Data Structures Implementation (C++)

## Overview
From-scratch implementation of a **Singly Linked List** and a **Binary Search Tree (BST)** in C++ supporting insertion, deletion, and search operations.

## Build & Run Commands
Ensure you have `g++` installed, then run:
```bash
g++ -std=c++17 task1_ds.cpp -o task1
./task1
```
*(On Windows Command Prompt, run `task1.exe` instead of `./task1`)*

## Complexity Summary
* **Singly Linked List:** Insert `O(n)`, Delete `O(n)`, Search `O(n)` | Space `O(1)`
* **Binary Search Tree:** Insert `O(h)`, Delete `O(h)`, Search `O(h)` *(where `h` is height; `O(log n)` average, `O(n)` worst)*
