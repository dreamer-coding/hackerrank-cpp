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
#include <algorithm>

int main() {
    int number;
    std::cin >> number;

    std::vector<int> vect(number);
    for (int iter = 0; iter < number; iter++) {
        std::cin >> vect[iter];
    }

    long unsigned int remove_position, erase_start, erase_end;
    std::cin >> remove_position >> erase_start >> erase_end;

    // Remove element at the specified position
    if (remove_position >= 1 && remove_position <= vect.size()) {
        vect.erase(vect.begin() + remove_position - 1);
    }

    // Remove the range of elements
    if (erase_start >= 1 && erase_end <= vect.size() && erase_start <= erase_end) {
        vect.erase(vect.begin() + erase_start - 1, vect.begin() + erase_end - 1);
    }

    std::cout << vect.size() << std::endl;
    for (int iter : vect) {
        std::cout << iter << " ";
    }
    return 0;
} // end of main
