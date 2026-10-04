# RayForge

RayForge is a C++20 CPU ray tracer project focused on learning modern C++,
memory management, data layout, cache locality, multithreading, and
performance optimization.

## Tech Stack

- C++20
- CMake
- GoogleTest

## Build

```bash
cmake -S . -B build
cmake --build build
```

## Tests

```bash
ctest --test-dir build --output-on-failure
```
