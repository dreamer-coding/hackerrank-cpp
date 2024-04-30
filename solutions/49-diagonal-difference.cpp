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
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

//
// Should add the values from the vector matrix
// into different summary values and return the
// absolute diagonal difference.
//
// arg-list:
//  -> arr: the vector being passed in
//
int diagonalDifference(vector<vector<int>> arr) {
    auto sum1 = 0;
    auto sum2 = 0;
    auto col = 0;

    for (auto row = 0U; row < arr.size(); ++row) {
        sum1 += arr[row][col];
        col++;
    } // end for

    col = arr[0].size() - 1;
    for (auto row = 0; col > -1; ++row) {
        sum2 += arr[row][col];
        col--;
    } // end for

    return abs(sum1 - sum2);
} // end of func

//
// main is where all C++ programs start
//
auto main() -> int {
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> arr(n);

    for (int i = 0; i < n; i++) {
        arr[i].resize(n);

        string arr_row_temp_temp;
        getline(cin, arr_row_temp_temp);

        vector<string> arr_row_temp = split(rtrim(arr_row_temp_temp));

        for (int j = 0; j < n; j++) {
            int arr_row_item = stoi(arr_row_temp[j]);
            arr[i][j] = arr_row_item;
        } // end for
    } // end for

    int result = diagonalDifference(arr);

    fout << result << "\n";
    fout.close();
    return 0;
} // end of func

//
// Should trim the data read in from the test case
// file being used in this problem.
//
// arg-list:
//  -> str: string reference being passed in for left trim
//
string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), [](unsigned char ch) { return !isspace(ch); })
    );

    return s;
} // end of func

//
// Should trim the data read in from the test case
// file being used in this problem.
//
// arg-list:
//  -> str: string reference being passed in for right trim
//
string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), [](unsigned char ch) { return !isspace(ch); }).base(),
        s.end()
    );

    return s;
} // end of func

//
// Should split the data into tokens so they can be used
// in the problem.
//
// arg-list:
//  -> str: string reference being passed in for left trim
//
vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
    } // end while

    tokens.push_back(str.substr(start));

    return tokens;
} // end of func
