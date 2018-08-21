#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (auto x:v)
        cout << x << " ";
    cout <<"] " << endl;
}
// Accepted
// reference: http://www.stanford.edu/class/cs124/lec/med.pdf 
int minDistance(string w1, string w2) {
    int m = w1.size(), n=w2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    // initialize 
    // 0 means pos in w1
    // i means pos in w2
    for (int i=0; i<=n; i++) dp[0][i] = i;     
    for (int i=0; i<=m; i++) dp[i][0] = i;        
    for (int i=1; i<=m; ++i) 
        for (int j=1; j<=n; ++j) {
            int t = min(dp[i-1][j] + 1,     // delection 
                        dp[i][j-1] + 1);    // insertion
            dp[i][j] = min(t, w1[i-1]==w2[j-1] ? dp[i-1][j-1] : dp[i-1][j-1] + 1);
        }
    return dp[m][n];
}

// optimized for extra space also accepted
int minDistance(string w1, string w2) {
    int m = w1.size(), n=w2.size();
    vector<int> pre(m+1, 0);
    vector<int> cur(m+1, 0);

    for (int i=0; i<=m; i++)
       pre[i] = i;        

    for (int j=1; j<=n; ++j)  {
        cur[0] = j;
        for (int i=1; i<=m; ++i) {
            cur[i] = min(min(cur[i-1]+1, pre[i]+1), 
                        w1[i-1]==w2[j-1] ? pre[i-1]:pre[i-1]+1);
        }
        pre = cur;
    }
    // NOTE: pre not cur
    return pre[m];
}

int main(int argc, char** argv) {
    return 0;
}
