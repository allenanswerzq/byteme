#include <cstdio>  
#include <cmath>
#include <climits>
#include <cstdlib>
#include <ctype.h> // <cctype> isalpha isdigit
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>   // std:string std:stoi
#include <queue>
#include <deque>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (auto x:v)
        cout << x << " ";
    cout <<"] " << endl;
}

// Perfect
int findLongestChain(vector<vector<int>>& pairs) {
    int n = pairs.size();
    sort(pairs.begin(), pairs.end());
    vector<int> dp(n, 0);
    dp[0] = 1;
    for (int i=1; i<n; ++i) {
        for (int j=0; j<i; ++j) {
            if (pairs[i][0] > pairs[j][1])
                dp[i] = max(dp[i], dp[j]+1);
            else 
                dp[i] = max(dp[i], dp[j]);
        }
    }    
    return dp[n-1];
}

int main(int argc, char** argv) {
    return 0;
}
