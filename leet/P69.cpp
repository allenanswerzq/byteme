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

// Integer square root
// https://en.wikipedia.org/wiki/Integer_square_root#Using_only_integer_division
// newton's iterative approach
int mySqrt1(int n) {
    // must be long long casue below operator x*x
    long long  x = n;
    while(x*x > n) {
        x = (x +n/x) / 2;
    }
    return x; 
}

// Accpepted
// also note that when submit solution need to comment cout  or it will TLE
int mySqrt3(int n) {
    if (!n) return 0;
    long x = n;
    long y;
    while(1) {
        // NOTE: both division are integer division
        // means the result is quotient
        // thus making the use of float unnecessary
        y = (x +n/x) / 2;
        if (abs(y-x)<1  || y-x==1) break;
        cout << y << " " << x << endl;
        x = y;
    }
    if (y-x == 1) return x;
    return y; 
}

int mySqrt(int n) {
    if (!n) return 0;
    double x = n;
    double y;
    while(1) {
        // this time both division are float division
        // you can see the difference
        y = (x + n/x) / 2;
        if (abs(y-x)<1) break;
        cout << y << " " << x << endl;
        x = y;
    }
    return y; 
}

// binary search approach
int mySqrt4(int n) {
    if(n == 0) return 0;
    // NOTE: use fabs for n overflow abs not working
    int lo=1, hi=fabs(n+1)/2;
    int ans=0;
    //cout << lo << " " << hi << endl;
    while (lo <= hi) {
        int mid = lo + (hi-lo)/2;
        // NOTE: wrote down this so mid dont need be long long type
        if (mid <= x/mid) {
            lo = mid+1;
            ans = mid; // the max postion that value <= x
        } else
            hi = mid-1;
    }
    return ans;
}


int mySqrt(int n) {
    if(n == 0) return 0;
    // NOTE: use fabs for n overflow abs not working
    int lo=1, hi=fabs(n+1)/2;
    //cout << lo << " " << hi << endl;
    while (hi-lo > 1) {
        int mid = lo + (hi-lo)/2;
        mid > x/mid ? hi=mid : lo=mid;
    }
    return mid;
}

int main(int argc, char** argv) {
    cout << mySqrt(INT_MAX) << endl;
    cout << mySqrt(1579205274) << endl;
    return 0;
}
