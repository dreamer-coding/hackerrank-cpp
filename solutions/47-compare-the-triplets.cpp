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
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

std::string ltrim(const std::string &);
std::string rtrim(const std::string &);
std::vector<std::string> split(const std::string &);

std::vector<int> compareTriplets(const std::vector<int>& a, const std::vector<int>& b) {
    int alice = 0, bob = 0;
    for (auto i = 0U; i < a.size(); ++i) {
        if (a[i] > b[i]) {
            ++alice;
        } else if (a[i] < b[i]) {
            ++bob;
        }
    }
    return std::vector<int>{alice, bob};
}

int main() {
    std::ofstream fout(std::getenv("OUTPUT_PATH"));

    std::string a_temp_temp;
    std::getline(std::cin, a_temp_temp);
    std::vector<std::string> a_temp = split(rtrim(a_temp_temp));
    std::vector<int> a(3);
    for (size_t i = 0; i < 3; ++i) {
        int a_item = std::stoi(a_temp[i]);
        a[i] = a_item;
    }

    std::string b_temp_temp;
    std::getline(std::cin, b_temp_temp);
    std::vector<std::string> b_temp = split(rtrim(b_temp_temp));
    std::vector<int> b(3);
    for (size_t i = 0; i < 3; ++i) {
        int b_item = std::stoi(b_temp[i]);
        b[i] = b_item;
    }

    std::vector<int> result = compareTriplets(a, b);
    for (size_t i = 0; i < result.size(); ++i) {
        fout << result[i];
        if (i != result.size() - 1) {
            fout << " ";
        }
    }
    fout << "\n";
    fout.close();

    return 0;
}

std::string ltrim(const std::string &str) {
    std::string s(str);
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) { return !std::isspace(ch); }));
    return s;
}

std::string rtrim(const std::string &str) {
    std::string s(str);
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) { return !std::isspace(ch); }).base(), s.end());
    return s;
}

std::vector<std::string> split(const std::string &str) {
    std::vector<std::string> tokens;
    std::string::size_type start = 0;
    std::string::size_type end = 0;
    while ((end = str.find(" ", start)) != std::string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(str.substr(start));
    return tokens;
}

//
// Should trim the data read in from the test case
// file being used in this problem.
//
// arg-list:
//  -> str: string refrence being passed in for left trim
//
string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
} // end of func

//
// Should trim the data read in from the test case
// file being used in this problem.
//
// arg-list:
//  -> str: string refrence being passed in for right trim
//
string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
} // end of func

//
// Should split the data into tokens so they can be used
// in the problem.
//
// arg-list:
//  -> str: string refrence being passed in for left trim
//
vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
    } // end while

    tokens.push_back(str.substr(start));

    return tokens;
} // end of func
