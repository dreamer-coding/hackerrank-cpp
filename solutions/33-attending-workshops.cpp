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

// Define the structs Workshops and Available_Workshops.
// Implement the functions initialize and CalculateMaxWorkshops
struct Workshop {
    int start_time;
    int duration;
    int end_time;
};

// Define the Available_Workshops struct
struct Available_Workshops {
    int n;
    Workshop* workshops;
};

// Function to initialize Available_Workshops object
Available_Workshops* initialize(int start_time[], int duration[], int n) {
    Available_Workshops* ptr = new Available_Workshops;
    ptr->n = n;
    ptr->workshops = new Workshop[n];
    for (int i = 0; i < n; ++i) {
        ptr->workshops[i].start_time = start_time[i];
        ptr->workshops[i].duration = duration[i];
        ptr->workshops[i].end_time = start_time[i] + duration[i];
    }
    return ptr;
}

// Function to calculate the maximum number of workshops that can be attended
int CalculateMaxWorkshops(Available_Workshops* ptr) {
    Workshop* workshops = ptr->workshops;

    // Sort workshops based on end time using lambda function
    std::sort(workshops, workshops + ptr->n, [](const Workshop& w1, const Workshop& w2) {
        return w1.end_time < w2.end_time;
    });

    int maxWorkshops = 0;
    int prevEndTime = 0;

    for (int i = 0; i < ptr->n; ++i) {
        if (workshops[i].start_time >= prevEndTime) {
            maxWorkshops++;
            prevEndTime = workshops[i].end_time;
        }
    }
    return maxWorkshops;
}

int main() {
    int n; // number of workshops
    std::cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for (int i = 0; i < n; i++) {
        std::cin >> start_time[i];
    }
    for (int i = 0; i < n; i++){
        std::cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time, duration, n);
    std::cout << CalculateMaxWorkshops(ptr) << std::endl;

    delete[] start_time;
    delete[] duration;
    delete ptr->workshops;
    delete ptr;
    return 0;
} // end of main
