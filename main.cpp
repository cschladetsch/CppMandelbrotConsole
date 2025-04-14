#include <iostream>
#include <complex>
#include <thread>
#include <chrono>
#include "external/rang.hpp"

using namespace std;
using namespace rang;

constexpr int WIDTH = 50;
constexpr int HEIGHT = 80;
constexpr int MAX_ITER = 100;

void moveCursor(int x, int y) {
    cout << "\033[" << y + 1 << ";" << x + 1 << "H";
}

void renderMandelbrot(double zoom) {
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            // Map screen coordinates to complex plane with offset
            double real = (x - WIDTH/2.0) * 4.0/(WIDTH * zoom) - 0.5;  // Offset by -0.5
            double imag = (y - HEIGHT/2.0) * 4.0/(WIDTH * zoom);
            
            complex<double> c(real, imag);
            complex<double> z = 0;
            
            int iter = 0;
            while (abs(z) < 2.0 && iter < MAX_ITER) {
                z = z * z + c;
                iter++;
            }
            
            moveCursor(x, y);
            
            if (iter == MAX_ITER) {
                cout << style::bold << fg::gray << "@";
            } else {
                // Different characters for different iteration depths
                char ch;
                if (iter < MAX_ITER/4) ch = '.';
                else if (iter < MAX_ITER/2) ch = 'o';
                else if (iter < 3*MAX_ITER/4) ch = 'O';
                else ch = '*';
                
                switch(iter % 6) {
                    case 0: cout << style::bold << fg::blue << ch; break;
                    case 1: cout << style::bold << fg::magenta << ch; break;
                    case 2: cout << style::bold << fg::cyan << ch; break;
                    case 3: cout << style::bold << fg::red << ch; break;
                    case 4: cout << style::bold << fg::yellow << ch; break;
                    default: cout << style::bold << fg::green << ch; break;
                }
            }
        }
    }
    cout << flush;
}

int main() {
    // Clear screen once and hide cursor
    cout << "\033[2J";
    cout << "\033[?25l";
    
    double zoom = 1.0;
    
    while (true) {
        renderMandelbrot(zoom);
        
        // Very slow zoom to see the details
        zoom *= 1.02;
        
        if (zoom > 20.0) {
            zoom = 1.0;
            cout << "\033[2J";  // Clear on reset
        }
        
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    
    // Show cursor before exit
    cout << "\033[?25h";
    return 0;
}
