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
// It should return the number of integers
// that are between the sets.
//
// arg-list:
//  -> a: first vector being compared
//  -> b: second vector being compared
//
int getTotalX(vector<int> a, vector<int> b)
{
    // Initialize iterators
    auto it1 = a.begin();
    auto it2 = b.begin();
    auto isFactor = false; // Used to keep track if it is a factor
    auto count = 0;        // Keeps track of answer
    
    //
    // Vector for storing integers in the first
    // and second step.
    //
    vector<int> factors1{};
    vector<int> factors2{};

    //
    // here we calculate the first array of factor elements
    //
    for (auto iter = a.back(); iter <= b.front() ; iter++)
    {
        isFactor = false; // Reset the value to false for reuse
        it1 = a.begin();  // Initialize factors iterator
        
        //
        // here we check if integer between array has
        // factors of vector array 'a'.
        //
        while (it1 != a.end())
        {
            if (iter % *it1 == 0)
            {
                isFactor = true;
            } // end if
            else
            {
                isFactor = false;
                break;
            } // end else
            ++it1;
        } // end while

        if (isFactor)
        {
            factors1.push_back(iter);
        } // end if

    } // end for

    //
    // we calculate the second vector array factor
    // elements here.
    //
    it2 = b.begin();
    auto it3 = factors1.begin();
    while (it3 != factors1.end())
    {
        it2 = b.begin();
        isFactor = false;
        while (it2 != b.end())
        {
            if (*it2 % *it3 == 0)
            {
                isFactor = true;
            } // end if
            else
            {
                isFactor = false;
                break;
            } // end else
            ++it2;
        } // end while
        if (isFactor)
        {
            factors2.push_back(*it3);
            ++count;
        } // end if
        ++it3;
    } // end while

    return count;
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

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    } // end for

    string brr_temp_temp;
    getline(cin, brr_temp_temp);

    vector<string> brr_temp = split(rtrim(brr_temp_temp));

    vector<int> brr(m);

    for (int i = 0; i < m; i++)
    {
        int brr_item = stoi(brr_temp[i]);

        brr[i] = brr_item;
    } // end for

    int total = getTotalX(arr, brr);

    fout << total << "\n";

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
