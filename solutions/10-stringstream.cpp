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
#include <sstream>
#include <string>
#include <vector>

std::vector<int> parseInts(const std::string& str) {
    std::stringstream ss(str);
    std::vector<int> vect;

    int number;
    char comma;

    while (ss >> number) {
        vect.push_back(number);
        if (ss >> comma && comma != ',') {
            ss.putback(comma);
        } // end if
    } // end while

    return vect;
}

int main() {
    std::string str;
    std::cin >> str;
    std::vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        std::cout << integers[i] << std::endl;
    }
    return 0;
} // end of main
