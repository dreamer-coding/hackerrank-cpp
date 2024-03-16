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
//  -> a: first vector being compared
//  -> b: second vector being compared
//
vector<int> compareTriplets(vector<int> a, vector<int> b)
{
   auto alice = 0, bob = 0;
   for (auto iter = 0U; iter < a.size(); iter++)
   {
       //
       // here we do a check to see if both
       // values from 'a' and 'b' are the same
       // and if so skip to the next value in
       // the vector else continue pass the if
       // and process the two values.
       //
       if (a[iter] == b[iter])
       {
           continue;
       } // end if

       //
       // here we check to see if the value in
       // 'a' index is greater than 'b' index
       // if so add one point to alice else add
       // one to bob's rating.
       //
       (a[iter] > b[iter])? alice++ : bob++;
   } // end for
   return std::vector<int> {alice, bob};
} // end func

//
// main is where all C++ programs start
//
auto main() -> int
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split(rtrim(a_temp_temp));

    vector<int> a(3);

    for (int i = 0; i < 3; i++)
    {
        int a_item = stoi(a_temp[i]);
        a[i] = a_item;
    } // end for

    string b_temp_temp;
    getline(cin, b_temp_temp);

    vector<string> b_temp = split(rtrim(b_temp_temp));

    vector<int> b(3);

    for (int i = 0; i < 3; i++)
    {
        int b_item = stoi(b_temp[i]);
        b[i] = b_item;
    } // end for

    vector<int> result = compareTriplets(a, b);

    for (auto i = 0U; i < result.size(); i++)
    {
        fout << result[i];

        if (i != result.size() - 1)
        {
            fout << " ";
        } // end if
    } // end for

    fout << "\n";

    fout.close();

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
