#include<bits/stdc++.h>

using namespace std;


int search(vector<int>& A, int target) {
    if(A.size() == 0) return 0;
    int lo =0, hi = A.size()-1;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if(A[mid] == target) return true;
        if(A[mid] > A[hi]) {
            if (A[lo] <= target && target < A[mid]) hi = mid - 1;
            else lo = mid + 1;
        } else if (A[mid] < A[hi]) {
            if(A[mid]<target && target <= A[hi]) lo = mid + 1;
            else hi = mid - 1;
        } else {
            hi--;
        }
    }
    return A[lo] == target ? true : false;
}

int main(int argc, char** argv) {
    return 0;
}
