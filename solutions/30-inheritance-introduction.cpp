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

class Triangle {
    public:
    void triangle() {
     		std::cout << "I am a triangle" << std::endl;
    }
};

class Isosceles : public Triangle {
    public:
    void isosceles() {
        std::cout << "I am an isosceles triangle" << std::endl;
    }
  	// Write your code here.
    void description() {
        std::cout << "In an isosceles triangle two sides are equal" << std::endl;
    }
};

int main() {
    Isosceles isc;
    isc.isosceles();
  	isc.description();
    isc.triangle();
    return 0;
} // end of main
