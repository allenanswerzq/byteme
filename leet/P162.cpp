#include <cstdio>  
#include <cmath>
#include <climits>
#include <cstdlib>
#include <ctype.h> // <cctype> isalpha isdigit
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>   // std:string std:stoi
#include <sstream>  // std:istringstream
#include <queue>
#include <deque>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (auto x:v)
        cout << x << " ";
    cout <<"] " << endl;
}

// need review
// binary seach approach
int findPeakElement(vector<int>& nums) {
    int lo=0; hi=nums.size()-1;
    while (lo < hi) {
        int mid = lo + (hi-lo)/2;
        if (nums[mid] > nums[mid+1])
            hi = mid;
        else
            lo = mid+1;
    }
    return lo;
}


// very smater one approch
int findPeakElement(vector<int>& nums) {
    for (int i=1; i<nums.size(); ++i)
        // because nums[-1] = nums[n] = -inf
        // the first descent positon is a peak
        // or it will be a ascent order, namely the last one is a peak
        if (nums[i-1] > nums[i])
            return i-1;

    return nums.size()-1;
}

int main(int argc, char** argv) {
    return 0;
}
