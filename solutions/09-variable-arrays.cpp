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
#include <vector>

int main() {
    int length, query, size;
    int index, element;
    std::cin >> length >> query;

    std::vector<std::vector<int>> arrays(length);

    for (auto i = 0; i < length; i++) {
        std::cin >> size;
        arrays[i].resize(size);
        for (auto j = 0; j < size; j++) {
            std::cin >> arrays[i][j];
        } // end for
    } // end for

    for (auto i = 0; i < query; i++) {
        std::cin >> index >> element;
        if (index >= 0 && index < length && element >= 0 && element < static_cast<int>(arrays[index].size())) {
            std::cout << arrays[index][element] << std::endl;
        } // end if
    } // end for
    return 0;
} // end of main
