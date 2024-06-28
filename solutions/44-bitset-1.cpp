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
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int N;
    unsigned int S, P, Q;
    cin >> N >> S >> P >> Q;

    unsigned int MOD = 1U << 31;
    unsigned int a = S % MOD;

    // Use a boolean array to mark presence of each value
    vector<bool> visited(MOD, false);
    visited[a] = true;

    int count = 1; // Start with the initial value

    for (int i = 1; i < N; ++i) {
        a = (a * P + Q) % MOD;
        if (!visited[a]) {
            visited[a] = true;
            ++count;
        }
    }

    cout << count << endl;
    return 0;
}
