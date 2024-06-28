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

using namespace std;

enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template <typename T> struct Traits;

template <>
struct Traits<Fruit> {
    static const char* name(int index) {
        switch (static_cast<Fruit>(index)) {
            case Fruit::apple: return "apple";
            case Fruit::orange: return "orange";
            case Fruit::pear: return "pear";
            default: return "unknown";
        }
    }
};

template <>
struct Traits<Color> {
    static const char* name(int index) {
        switch (static_cast<Color>(index)) {
            case Color::red: return "red";
            case Color::green: return "green";
            case Color::orange: return "orange";
            default: return "unknown";
        }
    }
};


int main() {
    int t = 0; std::cin >> t;

    for (int i = 0; i!=t; ++i) {
        int index1; std::cin >> index1;
        int index2; std::cin >> index2;
        cout << Traits<Color>::name(index1) << " ";
        cout << Traits<Fruit>::name(index2) << "\n";
    }
}
