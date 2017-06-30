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
    int lo=0, hi=A.size();
    while ( lo<=hi ) {
        if (A[lo]<=A[hi] && (target<A[lo] || target>A[hi])) 
            return -1;

        int mid = lo+(hi-lo)/2;
        if (A[mid] == target)
            return mid;
        // left part sorted
        if(A[hi]<A[mid] && A[lo]<=target && target<A[mid]) {
            hi = mid-1;
            continue;
        }
        // right part sorted
        if(A[mid]<A[hi] && A[mid]<target && target<=A[hi]) {
            lo = mid+1;
            continue;
        }
        // left part not sorted
        if (A[hi] > A[mid]) {
            hi = mid-1;
            continue;
        }
        if (A[mid] > A[hi]) {
            lo = mid+1;
            continue;
        }
    }  
    return -1;
}

int main(int argc, char** argv) {
    return 0;
}
