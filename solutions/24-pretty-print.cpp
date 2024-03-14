/*
==============================================================================
Author: Michael Gene Brockus (Dreamer)
Email: michaelbrockus@gmail.com
Organization: Fossil Logic
Description: 
    This file is part of the Fossil Logic project, where innovation meets
    excellence in software development. Michael Gene Brockus, also known as
    "Dreamer," is a dedicated contributor to this project. For any inquiries,
    feel free to contact Michael at michaelbrockus@gmail.com.
==============================================================================
*/
#include <iostream>
#include <iomanip> 

int main() {
    int T; std::cin >> T;
    std::cout << std::setiosflags(std::ios::uppercase);
    cout << std::setw(0xf) << internal;
    while (T--) {
		    double A; std::cin >> A;
		    double B; std::cin >> B;
		    double C; std::cin >> C;
        // Formatting and printing the numbers
        std::cout << std::hex << std::left << std::showbase << std::nouppercase << (long long) A << std::endl;
        std::cout << std::dec << std::right << std::setw(15) << std::setfill('_') << std::fixed << std::setprecision(2) << std::showpos << B << std::endl;
        std::cout << std::scientific << std::uppercase << std::noshowpos << std::setprecision(9) << C << std::endl;
    }
    return 0;
} // end of main
