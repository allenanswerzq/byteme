#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (auto x:v)
        cout << x << " ";
    cout <<"] " << endl;
}

bool recu(string s, set<string> wd) {
    if (s == "") return true;
    if (wd.find(s) != wd.end()) return true;
    for (int i=1; i<=s.size(); ++i) {
        string str = s.substr(0, i);
        if (wd.find(str) != wd.end()) {
            bool res = recu(s.substr(i), wd);
            if (res) return true;
        }
    }
    return false;
}

// recusive approach
// but there also have another recusive way
// recusively for loop on wordDcit not s
// unlucky, TLE
// 27/34 cases passed
bool wordBreak(string s, vector<string>& wordDict) {
    set<string> wd(wordDict.begin(), wordDict.end());
    return recu(s, wd);    
}

// optimized approach so it can be accepted
unordered_set<string> falses;
bool recu(string s, set<string> wd) {
    if (s == "") return true;
    // Note:
    if (falses.find(s) != falses.end()) return false;

    if (wd.find(s) != wd.end()) return true;
    for (int i=1; i<=s.size(); ++i) {
        string str = s.substr(0, i);
        if (wd.find(str) != wd.end()) {
            bool res = recu(s.substr(i), wd);
            if (res) return true;
        }
    }
    falses.insert(s);
    return false;
}

bool wordBreak(string s, vector<string>& wordDict) {
    set<string> wd(wordDict.begin(), wordDict.end());
    return recu(s, wd);    
}

// dp approach
// yes, accepted
bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> wd(wordDict.begin(), wordDict.end());
    int n = s.size();
    vector<bool> dp(n+1, 0);
    dp[0] = true;
    for (int i=1; i<=n; ++i) {
        if (wd.find(s.substr(0, i)) != wd.end()) dp[i] = true;
        else {
            for (int k=i-1; k>=0; --k) {
                if (dp[k]) {
                    string str = s.substr(k, i-k);
                    if (wd.find(str) != wd.end()) 
                        dp[i] = true;
                }
            }
        }
    }
    return dp[n];
}

// also BFS solution
// tansfer this problem to a graph
// very brilliant thought


int main(int argc, char** argv) {
    return 0;
}
