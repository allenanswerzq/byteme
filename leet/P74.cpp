#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (auto x:v)
        cout << x << " ";
    cout <<"] " << endl;
}

// binary search
// Accepted
bool searchMatrix(vector<vector<int>>& A, int target) {
    int m = A.size();
    if(m == 0) return false;
    int n = A[0].size();
    int lo = 0, hi = m * n - 1;
    while(lo <= hi) {
        int mid = lo + (hi-lo)/2;
        int med = A[mid / n][mid % n];
        if (med == target) return true;
        else if(med > target) hi = mid-1;
        else lo = mid+1;
    }
    return false;
}

int main(int argc, char** argv) {
    return 0;
}
