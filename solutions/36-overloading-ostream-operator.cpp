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

class Person {
public:
    Person(const std::string& first_name, const std::string& last_name) : first_name_(first_name), last_name_(last_name) {}
    const std::string& get_first_name() const {
      return first_name_;
    }
    const std::string& get_last_name() const {
      return last_name_;
    }
private:
    std::string first_name_;
    std::string last_name_;
};

// To fix this I added an overload operator
// to ensure expected output
std::ostream& operator<<(std::ostream& os, const Person& p) {
    os << "first_name=" << p.get_first_name() << ',' << "last_name=" << p.get_last_name();
    return os;
}

int main() {
    std::string first_name, last_name, event;
    std::cin >> first_name >> last_name >> event;
    auto p = Person(first_name, last_name);
    std::cout << p << " " << event << std::endl;
    return 0;
} // end of main
