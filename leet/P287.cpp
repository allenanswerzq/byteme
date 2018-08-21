#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (auto x:v)
        cout << x << " ";
    cout <<"] " << endl;
}

// accpeted
// but time complexity is O(nlogn) maybe
int findDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for (int i=0; i<nums.size()-1; ++i) 
        if (nums[i] == nums[i+1])
            return nums[i];
    return -1;
}

// use extra space 
// time complexity is O(n)
int findDuplicate(vector<int>& nums) {
    vector<int> cnt(nums.size(), 0);
    for (auto x : nums) 
        cnt[x]++;
    for (int i=1; i<nums.size(); ++i)
        if (cnt[i] > 1)
            return i;
    return -1;
}

// transform original problem into a cycle detection problem
// define f(i) = A[i] maps domain into itself
// if i != j such that f(i) == f(i)
// then A[i] is the answer
int findDuplicate(vector<int>& nums) {
    
}

int main(int argc, char** argv) {
    return 0;
}
