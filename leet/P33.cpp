#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (auto x:v)
        cout << x << " ";
    cout <<"] " << endl;
}

// not accepted
int search(vector<int>& A, int target) {
    int lo=0, hi=A.size()-1;
    while (lo <= hi) {
        int mid = lo+(hi-lo)/2;
        if (A[mid] == target) return mid;
        // A[0...mid] sorted
        if (A[0]<=target && target<A[mid])
            hi = mid - 1;
        // A[mid...hi] sorted
        if (target<A[mid] && A[mid]<A[0])
            hi = mid - 1;
        if (A[mid]<A[0] && A[0]<target)
            lo = mid + 1;
    }
    return -1;
}

// IDEA: one half of A must be sorted
int search(vector<int>& A, int target) {
    if (A.size() == 0) return -1;
    int lo=0, hi=A.size() - 1;
    while ( lo < hi ) {
        if (A[lo]<=A[hi] && (target<A[lo] || target>A[hi])) 
            return -1;

        int mid = lo+(hi-lo)/2;
        if (A[mid] == target)
            return mid;
        // left part sorted
        if(A[mid] > A[hi]) {
            if (A[lo]<=target && target<A[mid]) hi = mid-1;
            else lo = mid + 1;
        } else if (A[mid] < A[hi]) {
            // right part sorted
            if(A[mid]<target && target<=A[hi]) lo = mid + 1;
            else hi = mid - 1;
        }

    }  
    return A[lo] == target ? lo : -1;
}

int main(int argc, char** argv) {
    return 0;
}
