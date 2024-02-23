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
#include <sstream>
#include <exception>

class BadLengthException : public std::exception {
private:
    int length_;

public:
    BadLengthException(int length) : length_(length) {}

    int what() const noexcept override {
        return this->length_;
    }
};

bool checkUsername(const std::string& username) {
    bool isValid = true;
    int n = username.length();

    if (n < 5) {
        throw BadLengthException(n);
    }

    for (int i = 0; i < n - 1; i++) {
        if (username[i] == 'w' && username[i + 1] == 'w') {
            isValid = false;
        }
    }

    return isValid;
}

int main() {
    int T;
    std::cin >> T;

    while (T--) {
        std::string username;
        std::cin >> username;

        try {
            bool isValid = checkUsername(username);

            if (isValid) {
                std::cout << "Valid" << std::endl;
            } else {
                std::cout << "Invalid" << std::endl;
            }
        } catch (const BadLengthException& e) {
            std::cout << "Too short: " << e.what() << std::endl;
        }
    }

    return 0;
} // end of main
