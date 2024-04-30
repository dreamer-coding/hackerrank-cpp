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

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

vector<int> compareTriplets(const vector<int>& a, const vector<int>& b) {
    int alice = 0, bob = 0;
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] > b[i]) {
            ++alice;
        } else if (a[i] < b[i]) {
            ++bob;
        }
    }
    return vector<int>{alice, bob};
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string a_temp_temp;
    getline(cin, a_temp_temp);
    vector<string> a_temp = split(rtrim(a_temp_temp));
    vector<int> a(3);
    for (size_t i = 0; i < 3; ++i) {
        int a_item = stoi(a_temp[i]);
        a[i] = a_item;
    }

    string b_temp_temp;
    getline(cin, b_temp_temp);
    vector<string> b_temp = split(rtrim(b_temp_temp));
    vector<int> b(3);
    for (size_t i = 0; i < 3; ++i) {
        int b_item = stoi(b_temp[i]);
        b[i] = b_item;
    }

    vector<int> result = compareTriplets(a, b);
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

string ltrim(const string &str) {
    string s(str);
    s.erase(s.begin(), find_if(s.begin(), s.end(), [](int ch) { return !isspace(ch); }));
    return s;
}

string rtrim(const string &str) {
    string s(str);
    s.erase(find_if(s.rbegin(), s.rend(), [](int ch) { return !isspace(ch); }).base(), s.end());
    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;
    string::size_type start = 0;
    string::size_type end = 0;
    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(str.substr(start));
    return tokens;
}
