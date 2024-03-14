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
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    int number;
    std::cin >> number;

    std::vector<int> vect(number);
    for (auto iter = 0; iter < number; iter++) {
        std::cin >> vect[iter];
    }

    std::sort(vect.begin(), vect.end());

    for (auto iter : vect) {
        std::cout << iter << " ";
    }
    return 0;
} // end of main
