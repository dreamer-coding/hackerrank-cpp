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
    int number;
    long large_number;
    char letter;
    float point;
    double large_point;

    std::cin >> number >> large_number;
    std::cin >> letter;
    std::cin >> point >> large_point;
    
    std::cout << number << std::endl;
    std::cout << large_number << std::endl;
    std::cout << letter << std::endl;
    std::cout << std::fixed << std::setprecision(3) << point << std::endl;
    std::cout << std::fixed << std::setprecision(9) << large_point << std::endl;
    return 0;
} // end of main
