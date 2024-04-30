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
#include <algorithm>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

//
// Given an array of integers, calculate the
// ratios of its elements that are positive,
// negative, and zero. Print the decimal
// value of each fraction on a new line with
// 6 places after the decimal.
//
// Print the ratios of positive, negative and
// zero values in the array. Each value should
// be printed on a separate line with 6 digits
// after the decimal. The function should not
// return a value.
//
// arg-list:
//  -> arr: the vector being passed in
//
void plusMinus(vector<int> arr)
{
    uint64_t n;
    cin >> n;

    for (auto iter = 0U; iter < arr.size(); iter++)
    {
       cin >> arr[iter];
    } // end for
    auto fr1 = 0.0, fr2 = 0.0, fr3 = 0.0;

    for (auto iter = 0U; iter < arr.size(); iter++)
    {
        if (arr[iter] > 0)
        {
            fr1++;
        } // end if
        if (arr[iter] < 0)
        {
            fr2++;
        } // end if
        if (arr[iter] == 0)
        {
            fr3++;
        } // end if
    } // end for
    cout.precision(6);
    cout << (fr1 / arr.size()) << endl;
    cout << (fr2 / arr.size()) << endl;
    cout << (fr3 / arr.size()) << endl;
} // end of func

//
// main is where all C++ programs start
//
auto main() -> int
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        int arr_item = stoi(arr_temp[i]);
        arr[i] = arr_item;
    } // end for

    plusMinus(arr);

    return 0;
} // end of func

//
// Should trim the data read in from the test case
// file being used in this problem.
//
// arg-list:
//  -> str: string reference being passed in for left trim
//
string ltrim(const string &str)
{
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
string rtrim(const string &str)
{
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
