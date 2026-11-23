# Parts Operations Manager

A C++ console application for managing parts and operations using dynamic arrays, CRUD workflows, and dynamic action logging.

## Overview

This project implements a console-based operations management system in C++ built around dynamic memory management and structured records to track parts data and operational actions.

## Key Features

- **Parts & Operations CRUD:** Add, view, update, and manage parts and operational records.
- **Dynamic Memory Management:** Uses dynamically allocated arrays and custom cleanup routines.
- **Dynamic Action Logging:** Records runtime operations as actions occur during execution.

## How to Build and Run

Compile `main.cpp` using a C++ compiler (such as `g++` or Visual Studio / MSVC):

```bash
g++ -std=c++17 main.cpp -o parts_operations_manager

./parts_operations_manager
