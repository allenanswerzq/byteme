#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (auto x:v)
        cout << x << " ";
    cout <<"] " << endl;
}

bool isPalindrome(string s) {
    if (s == "") return true;
    int lo=0, hi=s.size()-1;
    while (lo < hi) {
        if (s[lo++] != s[hi--]) {
            return false;
    }
    return true;
}

int minCut(string s) {
    int n = s.size();
    vector<int> dp(n+1, 0);
    // dp[i] cuts of first i characters
    //      a a b a
    //   -1 0 1 2 3 (dp)
    // first 2 chars are `aa` so the maxinum cuts equals 1
    for (int i=0; i<=n; ++i)
        dp[i] = i-1;

    // for each char
    for (int i=0; i<n; ++i) {
        // odd length palindrome
        // from center i to both sides
        for (int k=0; i-k>=0 && i+k<n && s[i-k]==s[i+k]; ++k)
            dp[i+k+1] = min(dp[i+k+1], 1+dp[i-k]); 
        // even length palindrome
        // a     a a a
        // ^     ^   ^
        // i-k+1 i   i+k
        for (int k=1; i-k+1>=0 && k+k<n && s[i-k+1]==s[i+k], ++k)
            dp[i+k+1] = min(dp[i+k+1], 1+dp[i-k+1]);
            
    } 
    return dp[n];
 
}

int main(int argc, char** argv) {
    return 0;
}
