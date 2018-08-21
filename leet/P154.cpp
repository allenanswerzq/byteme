#include<bits/stdc++.h>

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
    while (lo < hi) {
        while(hi>=0 && nums[hi-1] == nums[hi]) --hi;
        while(lo<n-1 && nums[lo+1] == nums[lo]) ++lo;
        int mid = lo + (hi-lo)/2;
        if (nums[mid] <= nums[hi]){
            res = min(res, nums[mid]);
            hi = mid-1;
        } else {
            res = min(res, nums[lo]);
            lo = mid+1;
        }
    }    
    res = min(res, nums[lo]);
    return res;
}

int main(int argc, char** argv) {
    return 0;
}
