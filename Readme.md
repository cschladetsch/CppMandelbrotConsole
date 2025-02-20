# Mandelbrot Set Renderer

This is a **C++ terminal-based Mandelbrot set renderer** using `rang.hpp` for colored ASCII output. The program generates a **beautiful fractal** in your terminal with different colors and characters representing iteration depths.

## Features
? **ANSI Colors** via `rang.hpp`  
? **Optimized Aspect Ratio** for proper display in terminal  
? **Different Characters for Depth Representation** (`#`, `@`, `%`, `*`, `+`, `-`)  
? **Uses Efficient Complex Number Computation** to generate the Mandelbrot set  

### Install Dependencies
Ensure you have a **C++23 compiler** and CMake installed.
```sh
$ sudo apt install cmake g++
```
CMake will **auto-fetch `rang.hpp`** if it is missing.

### Build & Run
```sh
$ cmake -B build
$ cmake --build build
$ ./build/mandelbrot
```

## Troubleshooting
- If you see **garbled characters** (`????????`), your terminal may not support UTF-8.
  - Try running: `export LANG=en_US.UTF-8`
- If colors do not appear, try: `chcp 65001` in Windows Terminal.
- If `rang.hpp` is missing, run: `cmake --build build` to auto-fetch it.

## License
MIT License. Free to use and modify.
