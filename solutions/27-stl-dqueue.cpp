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
#include <deque>

void printKMax(int arr[], int n, int k){
    std::deque<int> pizza;

    // Process first k elements separately
    for (int i = 0; i < k; ++i) {
        // Remove elements smaller than arr[i] from the back
        while (!pizza.empty() && arr[i] >= arr[pizza.back()])
            pizza.pop_back();
        // Add current index to deque
        pizza.push_back(i);
    }

    // Process rest of the elements
    for (int i = k; i < n; ++i) {
        // The front of the deque is the maximum element for the previous window
        std::cout << arr[pizza.front()] << " ";

        // Remove elements outside the current window
        while (!pizza.empty() && pizza.front() <= i - k)
            pizza.pop_front();
        
        // Remove elements smaller than arr[i] from the back
        while (!pizza.empty() && arr[i] >= arr[pizza.back()])
            pizza.pop_back();
        
        // Add current index to deque
        pizza.push_back(i);
    }

    // Print maximum element of last window
    std::cout << arr[pizza.front()] << std::endl;
}

int main() {
    int t;
    std::cin >> t;
	  while (t > 0) {
		    int n, k;
    	  std::cin >> n >> k;
      	int i;
      	int arr[n];
      	for (i = 0; i < n; i++) {
            std::cin >> arr[i];
        }
        printKMax(arr, n, k);
        t--;
    }
    return 0;
} // end of main
