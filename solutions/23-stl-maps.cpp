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
#include <map>
#include <string>

int main() {
    int num_queries;
    std::cin >> num_queries;

    std::map<std::string, int> student_marks;

    for (int i = 0; i < num_queries; ++i) {
        int query_type;
        std::string name;
        std::cin >> query_type >> name;

        if (query_type == 1) {
            // Add marks to the student
            int marks;
            std::cin >> marks;
            student_marks[name] += marks;
        } else if (query_type == 2) {
            // Erase marks of the student
            student_marks.erase(name);
        } else if (query_type == 3) {
            // Print the marks of the student (if student not found, it will print 0)
            std::cout << student_marks[name] << std::endl;
        }
    }

    return 0;
} // end of main
