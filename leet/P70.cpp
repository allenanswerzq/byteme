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

// optimized for extra space
int climbStairs(int n) {
    int a=1, b=2, c;
    if(n == 1) return a;
    if(n == 2) return b;
    for (int i=2; i<n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;    
}

int climbStairs(int n) {
    vector<int> dp(n, 0);
    dp[0]=1; dp[1]=2;
    for (int i=2; i<n; ++i)
        dp[i] = dp[i-1] + dp[i-2];
    return dp[n-1];    
}

int main(int argc, char** argv) {
    return 0;
}
