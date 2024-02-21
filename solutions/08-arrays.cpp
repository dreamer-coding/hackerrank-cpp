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

int main() {
    size_t size;
    std::cin >> size;

    std::vector<int> vect;

    std::copy_n(std::istream_iterator<int>(std::cin), size, std::back_inserter(vect));

    reverse(vect.begin(), vect.end());

    for (auto i : vect) {
        std::cout << i << ' ';
    }
    return 0;
} // end of main
