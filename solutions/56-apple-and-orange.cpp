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
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

//
// Should compare the rating between vector array
// 'a' and vector array 'b', then it returns a
// vector with the rating values for the two.
//
// arg-list:
//  -> s: the starting point in the process
//  -> t: the ending point in the process
//  -> a: number of apples in the set
//  -> b: number of oarnges in the set
//  -> apples: array vector of apples
//  -> oranges: array vector of oranges
//
void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges)
{
    auto count1 = 0;
    auto count2 = 0;
    auto suma = 0, sumo = 0;

    for (auto iter : apples)
    {
        suma = a + iter;
        if (s <= suma && suma <= t)
        {
            count1++;
        } // end if

    } // end for
    cout << count1 << endl;

    for (auto iter : oranges)
    {
        sumo = b + iter;
        if (s <= sumo && sumo <= t)
        {
            count2++;
        } // end if

    } // end for
    cout << count2 << endl;

} // end of func

//
// main is where all C++ programs start
//
auto main() -> int
{
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int s = stoi(first_multiple_input[0]);

    int t = stoi(first_multiple_input[1]);

    string second_multiple_input_temp;
    getline(cin, second_multiple_input_temp);

    vector<string> second_multiple_input = split(rtrim(second_multiple_input_temp));

    int a = stoi(second_multiple_input[0]);

    int b = stoi(second_multiple_input[1]);

    string third_multiple_input_temp;
    getline(cin, third_multiple_input_temp);

    vector<string> third_multiple_input = split(rtrim(third_multiple_input_temp));

    int m = stoi(third_multiple_input[0]);

    int n = stoi(third_multiple_input[1]);

    string apples_temp_temp;
    getline(cin, apples_temp_temp);

    vector<string> apples_temp = split(rtrim(apples_temp_temp));

    vector<int> apples(m);

    for (int i = 0; i < m; i++)
    {
        int apples_item = stoi(apples_temp[i]);

        apples[i] = apples_item;
    } // end for

    string oranges_temp_temp;
    getline(cin, oranges_temp_temp);

    vector<string> oranges_temp = split(rtrim(oranges_temp_temp));

    vector<int> oranges(n);

    for (int i = 0; i < n; i++)
    {
        int oranges_item = stoi(oranges_temp[i]);

        oranges[i] = oranges_item;
    } // end for

    countApplesAndOranges(s, t, a, b, apples, oranges);

    return 0;
} // end of func

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
