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
// Define FUNCTION macro to define comparison functions
#define FUNCTION(name, opt) void name(int &x, int y){ !(x opt y) ? x = y : false; }

// Define foreach macro for iterating over vector indices
#define foreach(v, i) for(int i = 0; i < v.size(); i++)

// Define toStr macro for converting to string
#define toStr(S) #S

// Define io macro for output
#define io(v) std::cin >> v

// Define INF as a very large number
#define INF 10000000

// yet no cheese. Where is the cheese for my macro & cheese

#include <iostream>
#include <vector>

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main(){
	  int n; std::cin >> n;
  	std::vector<int> v(n);
	  foreach(v, i) {
		    io(v)[i];
  	}
	  int mn = INF;
	  int mx = -INF;
	  foreach(v, i) {
		    minimum(mn, v[I]);
		    maximum(mx, v[i]);
  	}
	  int ans = mx - mn;
	  std::cout << toStr(Result =) << ' ' << ans;
	  return 0;
} // end of main
