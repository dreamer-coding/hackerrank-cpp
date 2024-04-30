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
// For one act, we are given two kangaroos
// on a number line ready to jump in the
// positive direction (i.e., toward positive
// infinity).
//
// You have to figure out a way to get both
// kangaroos at the same location at the same
// time as part of the show. If it is possible,
// return YES, otherwise return NO.
//
// arg-list:
//  -> x1: kangaroo one
//  -> v1: kangaroo one speed
//  -> x2: kangaroo two
//  -> v2: kangaroo two speed
//
string kangaroo(int x1, int v1, int x2, int v2)
{
    if (v1 <= v2)
    {
        return "NO";
    } // end if
    else if (std::abs(x2 - x1) % std::abs(v2 - v1) == 0)
    {
        return "YES";
    } // end else if

    return "NO";
} // end of func

//
// main is where all C++ programs start
//
auto main() -> int
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int x1 = stoi(first_multiple_input[0]);

    int v1 = stoi(first_multiple_input[1]);

    int x2 = stoi(first_multiple_input[2]);

    int v2 = stoi(first_multiple_input[3]);

    string result = kangaroo(x1, v1, x2, v2);

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
string ltrim(const string &str)
{
    string s(str);
    s.erase(s.begin(), find_if(s.begin(), s.end(), [](unsigned char ch) { return !isspace(ch); }));
    return s;
}

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
    s.erase(find_if(s.rbegin(), s.rend(), [](unsigned char ch) { return !isspace(ch); }).base(), s.end());
    return s;
}

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
}
