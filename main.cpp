#include <iostream>
#include <complex>
#include "external/rang.hpp"

using namespace std;
using namespace rang;

constexpr int WIDTH = 120;  // Adjust for terminal width
constexpr int HEIGHT = 40;  // Adjust for proper aspect ratio
constexpr int MAX_ITER = 500;

// Clear screen function
void clearScreen() {
    cout << "\033[2J\033[H"; // ANSI escape sequence to clear screen
}

// Map iteration count to ANSI color sequence and character
void printMandelbrotPixel(int iter) {
    if (iter == MAX_ITER) cout << style::bold << fg::black << "#";
    else if (iter > MAX_ITER * 0.90) cout << fg::blue << "@";
    else if (iter > MAX_ITER * 0.75) cout << fg::magenta << "%";
    else if (iter > MAX_ITER * 0.50) cout << fg::cyan << "*";
    else if (iter > MAX_ITER * 0.25) cout << fg::green << "+";
    else cout << fg::yellow << "-";
}

void renderMandelbrot() {
    clearScreen();

    double realMin = -2.0, realMax = 1.0;
    double imagMin = -1.0, imagMax = 1.0;

    // Adjust aspect ratio for terminal characters
    double imagScale = (imagMax - imagMin) / HEIGHT;
    double realScale = (realMax - realMin) / WIDTH;

    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            double real = realMin + x * realScale;
            double imag = imagMax - y * imagScale;  // Flip y-axis
            complex<double> c(real, imag);
            complex<double> z = c;

            int iter = 0;
            while (abs(z) < 2.0 && iter < MAX_ITER) {
                z = z * z + c;
                ++iter;
            }

            // Print the colored character
            printMandelbrotPixel(iter);
        }
        cout << "\n";  // Newline for next row
    }
    cout << flush;  // Ensure output is flushed immediately
}

int main() {
    renderMandelbrot();
    return 0;
}
