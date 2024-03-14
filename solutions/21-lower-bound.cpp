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

    int queries;
    std::cin >> queries;

    for (int q = 0; q < queries; ++q) {
        int query;
        std::cin >> query;

        auto it = std::lower_bound(vect.begin(), vect.end(), query);

        if (it != vect.end() && *it == query) {
            std::cout << "Yes " << (it - vect.begin() + 1) << std::endl;
        } else {
            int next_smallest_index = it - vect.begin() + 1;
            if (next_smallest_index > number) {
                next_smallest_index = number + 1;
            }
            std::cout << "No " << next_smallest_index << std::endl;
        }
    }
    return 0;
} // end of main
