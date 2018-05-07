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
#include <tuple>
#include <queue>
#include <deque>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (auto x:v)
        cout << x << " ";
    cout <<"] " << endl;
}

int minSteps(int n) {
    int N = 1001;
    vector<int> dp(N, INT_MAX);
    dp[1] = 0;
    for (int i=1; i<N; ++i) {
        for (int j=2*i; j<N; j+=i) 
            dp[j] = min(dp[j], dp[i] + j/i);
    }
    return dp[n];
}

int main(int argc, char** argv) {
    return 0;
}
