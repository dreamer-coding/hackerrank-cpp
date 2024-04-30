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
#include <algorithm>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

//
// Should print and output a staircase based
// on the number of steps passed in.
//
// arg-list:
//  -> n: number of steps for the staircase
//
void staircase(int n)
{
    // We start with using a pair of const char type values.
    pair<const char, const char> box = {' ', '#'};
    for (int it = 0; it < n; it++)
    {
        // Here we set sub index to 'N' steps in array.
        // For sub index is greater than zero, iterate backward in the array.
        // In the loop, check to see if a step is greater than the iterator index plus one,
        // if it is, put a ' ' char in place, else put a '#'.
        for (int sub = n; sub > 0; sub--)
        {
            cout << ((sub > it + 1) ? box.first : box.second);
        }
        // Each time that sub loop is done, we output a newline char.
        cout << endl;
    }
}

//
// main is where all C++ programs start
//
int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    staircase(n);

    return 0;
}

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
