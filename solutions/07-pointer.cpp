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
#include <cmath>

void update(int* a, int* b) {
    int copy = *a;
    *a = *a + *b;
    *b = std::abs(copy - *b);
}

int main() {
    int a, b;
    int* pa = &a, * pb = &b;

    std::cin >> a >> b;
    update(pa, pb);
    std::cout << a << std::endl << b;

    return 0;
} // end of main
