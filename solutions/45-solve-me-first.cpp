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
#include <cstdint>
#include <iostream>
using namespace std;

//
// Should add the value of 'a' and 'b' and
// return the sum of two.
//
// arg-list:
//  -> a: first integer value being passed in
//  -> b: second integer value being passed in
//
decltype(auto) solveMeFirst(int64_t *a, int64_t *b)
{
    return *a + *b;
} // end of func

//
// main is where all C++ programs start
//
auto main() -> int
{
    int64_t num1, num2;
    int64_t sum;

    cin >> num1 >> num2;
    sum = solveMeFirst(&num1, &num2);
    cout << sum;

    return 0;
} // end of func
