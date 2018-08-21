#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (auto x:v)
        cout << x << " ";
    cout <<"] " << endl;
}

// Accepted
// but need more space
int minimumTotal(vector<vector<int>>& A) {
    int n=A.size(), m=A.back().size();
    if (n == 0) return 0;
    vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
    dp[0][0] = A[0][0];

    for (int i=1; i<n; ++i) {
        for (int j=0; j<A[i].size(); ++j) {
            if (j < A[i-1].size())
                dp[i][j] = min(dp[i][j], dp[i-1][j] + A[i][j]);
            if(j-1 >= 0)
                dp[i][j] = min(dp[i][j], dp[i-1][j-1] + A[i][j]);
        }
    }
    
    int res = INT_MAX;
    for (auto x: dp[n-1])
        res = min(res, x);
    return res;
}

int main(int argc, char** argv) {
    return 0;
}
