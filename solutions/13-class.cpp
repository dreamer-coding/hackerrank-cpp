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

class Student {
    private:
    std::string first_name;
    std::string last_name;
    int standard;
    int age;

    public:
    const int get_age() const {
        return this->age;
    } // end of method

    // getters
    const std::string get_first_name() const {
        return this->first_name;
    } // end of method

    const std::string get_last_name() const {
        return this->last_name;
    } // end of method

    const int get_standard() const {
        return this->standard;
    } // end of method

    // setters
    void set_age(const int update) {
        this->age = update;
    } // end of method

    void set_first_name(const std::string update) {
        this->first_name = update;
    } // end of method

    void set_last_name(const std::string update) {
        this->last_name = update;
    } // end of method

    void set_standard(const int update) {
        this->standard = update;
    } // end of method

    // utilits
    std::string to_string() const {
        return std::to_string(this->age) + "," + this->first_name + "," +
               this->last_name + "," + std::to_string(this->standard);
    } // end of method

}; // end class

int main() {
    int age, standard;
    std::string first_name, last_name;
    
    std::cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    std::cout << st.get_age() << std::endl;
    std::cout << st.get_last_name() << ", " << st.get_first_name() << std::endl;
    std::cout << st.get_standard() << std::endl;
    std::cout << std::endl;
    std::cout << st.to_string();
    return 0;
} // end of main
