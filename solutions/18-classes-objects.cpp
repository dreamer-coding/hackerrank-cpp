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
#include <algorithm>
#include <numeric>
#include <vector>

enum {SCORE_SIZE = 5};

class Student {
private:
    std::vector<int> scores;

public:
    void input() {
        scores.resize(SCORE_SIZE);
        for (auto& score : scores) {
            std::cin >> score;
        }
    }

    // Use accumulate algorithm to calculate total score
    int calculateTotalScore() const {
        return std::accumulate(scores.begin(), scores.end(), 0);
    }
};


int main() {
    int n; // number of students
    std::cin >> n;
    Student *s = new Student[n]; // an array of n students
    
    for(int i = 0; i < n; i++){
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0; 
    for(int i = 1; i < n; i++){
        int total = s[i].calculateTotalScore();
        if(total > kristen_score){
            count++;
        }
    }

    // print result
    std::cout << count;
    
    return 0;
    return 0;
} // end of main
