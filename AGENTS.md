# Agent Guidelines for C++ Array Project

## Build Commands
- Build all: `make` or `make all`
- Build executable: `make main`
- Build docs: `make docs`
- Run program: `make run`
- Clean: `make clean`

## Test Commands
- Compile tests: `g++ -std=c++23 -Wall -Wextra -g tests/test_Array.cpp src/*.cpp -o build/test_Array`
- Run all tests: `./build/test_Array`
- Run single test function: Modify test_Array.cpp main() to call only desired test function

## Code Style Guidelines

### Language & Standards
- C++23 standard
- Use `#pragma once` for header guards
- Include order: local headers first, then standard library

### Naming Conventions
- Classes: PascalCase (e.g., `Array`, `InvalidSizeException`)
- Methods: camelCase (e.g., `getMaxIndex()`, `getProductBetweenZeros()`)
- Variables: snake_case (e.g., `maxIdx`, `firstZero`, `secondZero`)
- Constants: UPPER_SNAKE_CASE (e.g., `SIZE`)

### Formatting
- 4-space indentation
- Consistent spacing around operators
- One statement per line

### Types & Error Handling
- Use `long long` for large integer products
- Custom exceptions inherit from `std::exception`
- Exception messages in Russian
- Use `const` for read-only methods and parameters

### Structure
- Separate declaration (.hpp) and implementation (.cpp)
- Private members first in classes
- Public interface follows private members