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
#include <set>

int main() {
    int num_queries;
    std::cin >> num_queries;

    std::set<int> my_set;

    for (int i = 0; i < num_queries; ++i) {
        int query_type, value;
        std::cin >> query_type >> value;

        if (query_type == 1) {
            // Add element to the set
            my_set.insert(value);
        } else if (query_type == 2) {
            // Delete element from the set
            my_set.erase(value);
        } else if (query_type == 3) {
            // Check if the element is present and print Yes or No
            std::cout << (my_set.count(value) ? "Yes" : "No") << std::endl;
        }
    }
    return 0;
} // end of main
