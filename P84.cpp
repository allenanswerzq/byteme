#include <cstdio>  
#include <cmath>
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (auto x:v)
        cout << x << " ";
    cout <<"] " << endl;
}

// Accepted
// But i dont know why
int largestRectangleArea(vector<int>& hist) {
       
    // Create an empty stack. The stack holds indexes of hist[] array
    // The bars stored in stack are always in increasing order of their
    // heights.
    // NOTE: push back 0
    hist.push_back(0);
    int n = hist.size();
    vector<int> s;

    int max_area = 0;   // Initalize max area
    int tp;             // To store top of stack
    int area_with_top;  // To store area with top bar as the smallest bar

    // Run through all bars of given histogram
    int i = 0;
    while (i < n)
    {
        
        // If this bar is higher than the bar on top stack, push it to stack
        if (s.empty() || hist[s.back()] <= hist[i])
            s.push_back(i++);

        // If this bar is lower than top of stack, then calculate area of 
        // rectangle with stack top as the smallest (or minimum height) bar. 
        // 'i' is 'right index' for the top and element before top in stack 
        // is 'left index'
        else
        {
            tp = s.back();   // store the top index
            s.pop_back();        // pop the top

            // Calculate the area with hist[tp] stack as smallest bar
            // width = right index - left index - 1
            area_with_top = hist[tp] * (s.empty() ? i-(-1)-1:i - s.back() - 1);

            // update max area, if needed
            if (max_area < area_with_top)
                max_area = area_with_top;
        }
    }
    return max_area;
}


int main(int argc, char** argv) {
    return 0;
}
