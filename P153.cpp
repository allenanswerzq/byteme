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

int findMin(vector<int>& nums) {
    int n = nums.size();
    int lo=0, hi=n-1;
    int res = INT_MAX;
    while (lo <= hi) {
        int mid = lo + (hi-lo)/2;
        if (nums[lo] <= nums[mid]) {
            res = min(nums[lo], res);
            lo = mid+1;
        } else {
            res = min(res, num[mid]);
            hi = mid-1; 
        }
    }    
    return res;
}

int main(int argc, char** argv) {
    return 0;
}
