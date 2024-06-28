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
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


class Complex {
public:
    int a, b;

    void input(string s) {
        int v1 = 0;
        int i = 0;
        while(s[i] != '+') {
            v1 = v1 * 10 + s[i] - '0';
            i++;
        }
        while(s[i] == ' ' || s[i] == '+' || s[i] == 'i') {
            i++;
        }
        int v2 = 0;
        while(i < s.length()) {
            v2 = v2 * 10 + s[i] - '0';
            i++;
        }
        a = v1;
        b = v2;
    }
};

// Overload the + operator to add two complex numbers
Complex operator+(const Complex &c1, const Complex &c2) {
    Complex temp;
    temp.a = c1.a + c2.a;
    temp.b = c1.b + c2.b;
    return temp;
}

// Overload the << operator to print the complex number in the desired format
ostream& operator<<(ostream &out, const Complex &c) {
    out << c.a << "+i" << c.b;
    return out;
}

int main() {
    Complex x, y;
    string s1, s2;
    cin >> s1 >> s2;
    x.input(s1);
    y.input(s2);
    Complex z = x + y;
    cout << z << endl;
    return 0;
}
