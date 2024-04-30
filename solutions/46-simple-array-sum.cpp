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

// Calculate the sum of elements in a vector
int simpleArraySum(const vector<int>& ar) {
    int sum = 0;
    for (int num : ar) {
        sum += num;
    }
    return sum;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string ar_count_temp;
    getline(cin, ar_count_temp);
    int ar_count = stoi(ltrim(rtrim(ar_count_temp)));

    string ar_temp_temp;
    getline(cin, ar_temp_temp);
    vector<string> ar_temp = split(rtrim(ar_temp_temp));
    vector<int> ar(ar_count);

    for (int i = 0; i < ar_count; i++) {
        int ar_item = stoi(ar_temp[i]);
        ar[i] = ar_item;
    }

    int result = simpleArraySum(ar);
    fout << result << "\n";
    fout.close();

    return 0;
}

string ltrim(const string &str) {
    return str.substr(str.find_first_not_of(' '));
}

string rtrim(const string &str) {
    return str.substr(0, str.find_last_not_of(' ') + 1);
}

vector<string> split(const string &str) {
    vector<string> tokens;
    size_t start = 0, end = 0;
    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(str.substr(start));
    return tokens;
}
