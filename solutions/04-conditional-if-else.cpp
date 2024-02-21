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
#include <map>

std::string ltrim(const std::string &str) {
    std::string s(str);

    s.erase(
        s.begin(),
        std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace)))
    );
    return s;
}

std::string rtrim(const std::string &str) {
    std::string s(str);

    s.erase(
        std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(),
        s.end()
    );
    return s;
}

int main() {
    std::string n_temp;
    std::getline(std::cin, n_temp);

    int number = std::stoi(ltrim(rtrim(n_temp)));

    std::map<int ,std::string> numbers = {
        {0, "zero" }, {1, "one"  },
        {2, "two"  }, {3, "three"},
        {4, "four" }, {5, "five" },
        {6, "six"  }, {7, "seven"},
        {8, "eight"}, {9, "nine" }
    };

    switch (number) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            std::cout << numbers[number] << std::endl;
            break;
        default:
            std::cout << "Greater than 9" << std::endl;
            break;
    } // end switch
    return 0;
} // end of main
