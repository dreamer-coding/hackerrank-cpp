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
#include <string>
#include <algorithm>

int main() {
    std::string first, second;
    std::cin >> first >> second;
 
    std::cout << first.size() << ' ' << second.size() << std::endl;
    std::cout << first + second << std::endl;

    if (!first.empty() && !second.empty()) {
        std::swap(first[0], second[0]);
    } // end if

    std::cout << first << ' ' << second << std::endl;
    return 0;
} // end of main
