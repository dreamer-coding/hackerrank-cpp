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
// Should for each set of data maintain
// process a record of play scores. The
// tabulates the number of times breaks
// the data point record for most points
// and least points in a game.
//
// Points scored in the establish record
// for the result.
//
// arg-list:
//  -> scores: vector array of scores
//
vector<int> breakingRecords(vector<int> scores)
{
    auto maxScore = 0;
    auto minScore = 0;
    auto maxCounter = 0;
    auto minCounter = 0;
    vector<int> results{};

    //
    // Initialize max and min scores
    //
    maxScore = scores[0];
    minScore = scores[0];

    for (auto iter : scores)
    {
        if (maxScore < iter)
        {
            maxScore = iter;
            ++maxCounter;
        } // end if
        else if (minScore > iter)
        {
            minScore = iter;
            ++minCounter;
        } // end else if

    } // end for

    //
    // then we fill in the results vector array
    // before sending it to out as a returned
    // value.
    //
    results.push_back(maxCounter);
    results.push_back(minCounter);

    return results;
} // end of func

//
// main is where all C++ programs start
//
auto main() -> int
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string scores_temp_temp;
    getline(cin, scores_temp_temp);

    vector<string> scores_temp = split(rtrim(scores_temp_temp));

    vector<int> scores(n);

    for (int i = 0; i < n; i++)
    {
        int scores_item = stoi(scores_temp[i]);

        scores[i] = scores_item;
    } // end for

    vector<int> result = breakingRecords(scores);

    for (size_t i = 0; i < result.size(); i++)
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
