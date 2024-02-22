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

// The class should have the following functions : 
class Box {
private:
    int length;  // box's length
    int breadth; // box's breadth
    int height;  // box's height

public:
    // Constructors:
    Box() : length(0), breadth(0), height(0) {}

    Box(int l, int b, int h) : length(l), breadth(b), height(h) {}

    Box(const Box& box) : length(box.length), breadth(box.breadth), height(box.height) {}

    int getLength() const {
        return length;
    }

    int getBreadth() const {
        return breadth;
    }

    int getHeight() const {
        return height;
    }

    long long CalculateVolume() const {
        return static_cast<long long>(length) * breadth * height;
    }

    // Overload operator < as specified
    bool operator<(const Box& B) const {
        return (length < B.length) || ((breadth < B.breadth) && (length == B.length)) ||
               ((height < B.height) && (length == B.length) && (breadth == B.breadth));
    }

    // Overload operator << as specified
    friend std::ostream& operator<<(std::ostream& out, const Box& B);
};

// Definition of the << operator
std::ostream& operator<<(std::ostream& out, const Box& B) {
    out << B.getLength() << ' ' << B.getBreadth() << ' ' << B.getHeight();
    return out;
}

int main() {
    int n;
    std::cin >> n;
    Box temp;

    for (int i = 0; i < n; i++) {
        int type;
        std::cin >> type;

        if (type == 1) {
            std::cout << temp << std::endl;
        }
        else if (type == 2) {
            int l, b, h;
            std::cin >> l >> b >> h;
            Box newBox(l, b, h);
            temp = newBox;
            std::cout << temp << std::endl;
        }
        else if (type == 3) {
            int l, b, h;
            std::cin >> l >> b >> h;
            Box newBox(l, b, h);
            if (newBox < temp) {
                std::cout << "Lesser\n";
            }
            else {
                std::cout << "Greater\n";
            }
        }
        else if (type == 4) {
            std::cout << temp.CalculateVolume() << std::endl;
        }
        else if (type == 5) {
            Box newBox(temp);
            std::cout << newBox << std::endl;
        }
    }

    return 0;
}
 // end of main
