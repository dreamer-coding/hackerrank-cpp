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
#include <map>

// Function to parse HRML and populate a map
std::map<std::string, std::string> parseHRML(int n) {
    std::map<std::string, std::string> m;
    std::string curr = "", attr_name;

    for (int i = 0; i < n; i++) {
        std::string line, tag, extract;
        std::getline(std::cin, line);
        std::stringstream ss(line);

        while (std::getline(ss, extract, ' ')) {
            if (extract[0] == '<') {
                if (extract[1] != '/') {
                    tag = extract.substr(1);
                    if (tag.back() == '>')
                        tag.pop_back();
                    if (!curr.empty())
                        curr += ".";
                    curr += tag;
                } else {
                    size_t pos = curr.find("." + extract.substr(2, extract.find('>') - 2));
                    if (pos != std::string::npos)
                        curr = curr.substr(0, pos);
                    else
                        curr.clear();
                }
            } else if (extract[0] == '"') {
                size_t pos = extract.find_last_of('"');
                std::string attr_value = extract.substr(1, pos - 1);
                m[attr_name] = attr_value;
            } else if (extract != "=") {
                attr_name = curr + "~" + extract;
            } // end if else's
        } // end while
    } // end for

    return m;
}

int main() {
    int n, q;
    std::cin >> n >> q;
    std::cin.ignore();

    std::map<std::string, std::string> m = parseHRML(n);

    std::string query;
    for (int i = 0; i < q; i++) {
        std::getline(std::cin, query);

        auto itr = m.find(query);
        if (itr != m.end()) {
            std::cout << itr->second << std::endl;
        } else {
            std::cout << "Not Found!" << std::endl;
        } // end if else
    } // end for
    return 0;
} // end of main
