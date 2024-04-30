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
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

//
// Should process a gven a time in 12-hour AM/PM
// format, convert it to military (24-hour) time
// and return that as the result.
//
// arg-list:
//  -> s: A single string thatrepresents a time
//
string timeConversion(string s) {
    string ans;
    cin >> s;

    if (s.substr(8, 8) == "AM") {
        if (s.substr(0, 2) == "12") {
            ans += "00";
        } else {
            ans += s.substr(0, 2);
        } // end else

    } else {
        if (s.substr(0, 2) == "12") {
            ans += "12";
        } else {
            auto hour = stoi(s.substr(0, 2));
            hour += 12;
            ans += to_string(hour);
        } // end else

    } // end else

    ans += s.substr(2, 6);

    return ans;
} // end of func

//
// main is where all C++ programs start
//
auto main() -> int {
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
} // end of func
