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
/*
 * Create classes Rectangle and RectangleArea
 */ 

class Rectangle {
    private:
    int height;
    int width;

    public:
    Rectangle() : height(0), width(0) {};

    void display() {
        std::cout << width << " " << height << std::endl;
    }
    
    void set_height(int new_height) {
        this->height = new_height;
    }

    void set_width(int new_width) {
        this->width = new_width;
    }
    
    int get_height() const {
        return height;
    }

    int get_width() const {
        return width;
    }
};

class RectangleArea : public Rectangle {
    public:
    int height;
    int width;

    void read_input() {
        std::cin >> this->width >> this->height;
        set_width(width);
        set_height(height);
    }

    void display() {
        std::cout << get_width() * get_height() << std::endl;
    }    
};


int main() {
    // Declare a RectangleArea object
    RectangleArea r_area;
    
    // Read the width and height
    r_area.read_input();
    
    // Print the width and height
    r_area.Rectangle::display();
    
    // Print the area
    r_area.display();
    return 0;
} // end of main
