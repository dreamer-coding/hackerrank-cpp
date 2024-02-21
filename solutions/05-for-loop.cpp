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
#include <map>

int main() {
    std::map<int, std::string> numbers = {
        {0, "zero"}, {1, "one"},
        {2, "two"}, {3, "three"},
        {4, "four"}, {5, "five"},
        {6, "six"}, {7, "seven"},
        {8, "eight"}, {9, "nine"}
    };
    
    int start, end;
    std::cin >> start >> end;

    auto get_output = [&numbers](int iter) {
        return numbers.count(iter) ? numbers[iter] : (iter % 2 == 0 ? "even" : "odd");
    }; // end lambda

    for (auto iter = start; iter <= end; ++iter) {
        cout << get_output(iter) << endl;
    }
    return 0;
} // end of main
