#include<bits/stdc++.h>

using namespace std;

bool isPalindrome(string s) {
    if (s == "") return true;
    int lo=0, hi=s.size()-1;
    while (lo < hi) {
        if (s[lo] == s[hi]) {
            ++lo;
            --hi;
        } else {
            return false;
        }
    }
    return true;
}

void bt(vector<vector<string>>& res, vector<string> ans, string s) {
    if (s == "") {
        res.push_back(ans);
        return;
    }
    for (int i=1; i<=s.size(); ++i) {
        string front = s.substr(0, i);
        if (isPalindrome(front)) {
            ans.push_back(front);
            bt(res, ans, s.substr(i));
            ans.pop_back();
        }
    }
}

// Backtracking approach
// Accepted
vector<vector<string>> partition(string s) {
    vector<vector<string>> res;            
    vector<string> ans;
    if (s == "") return res;
    bt(res, ans, s);
    return res;
}

// Finally, it worked
vector<vector<string>> partition(string s) {
    vector<vector<string>> rest;            
    vector<vector<string>> res;            
    if (s == "") return rest;
    for (int i=1; i<=s.size(); ++i) {
        string front = s.substr(0, i);
        if (isPalindrome(front)) {
            rest = partition(s.substr(i));
            if (rest.size() == 0) {
                res.push_back({front});
            } else {
                for (auto x: rest) {
                    x.insert(x.begin(), front);
                    res.push_back(x);
                }
            }
        }
    }
    return res;
}

int main(int argc, char** argv) {
    return 0;
}
