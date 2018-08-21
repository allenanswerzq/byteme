#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (auto x:v)
        cout << x << " ";
    cout <<"] " << endl;
}

// press N times
// output maximum number of 'A'
int maxA(int N) {
    // minimum output number should be n
    int res = N;
    for (int i=1; i<=N-3; ++i)    
        res = max(res, maxA(i) * (N-i-1));
    return res;
}

int maxA(int n) {
    vector<int> dp(n+1);
    for (int i=0; i<=n; ++i) {
        dp[i] = i;
        for (int j=1; j<=i-3; ++j)
            dp[i] = max(dp[i], dp[j] * (i-j-1));
    }
    return dp[n];
}

int main(int argc, char** argv) {
    return 0;
}
