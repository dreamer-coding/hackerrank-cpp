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
#include <numeric>

int main() {
    std::vector<int> vect;
    int num;

    for (int i = 0; i < 3; i++) {
        std::cin >> num;
        vect.push_back(num);
    } // end for

    int sum = std::accumulate(vect.begin(), vect.end(), 0);
    std::cout << sum << std::endl;
    return 0;
} // end of main
