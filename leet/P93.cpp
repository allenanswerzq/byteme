#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        for (int a = 1; a <=3; a++)
        for (int b = 1; b <=3; b++)
        for (int c = 1; c <=3; c++)
        for (int d = 1; d <=3; d++)
        if (a+b+c+d == s.length()) {
            int A = stoi(s.substr(0,a));
            int B = stoi(s.substr(a,b));
            int C = stoi(s.substr(a+b,c));
            int D = stoi(s.substr(a+b+c,d));
            if (A <= 255 && B <= 255 && C <= 255 && D <= 255) {
                string res = to_string(A) + "." + to_string(B) + "." + 
                             to_string(C) + "." + to_string(D);  
                if (res.length() == s.length() + 3) {
                    ans.push_back(res);
                }
            }  
        }
        return ans;
    }
};

void dfs(vector<string>& res, string path, string s, int k) {
    if (s=="" || k==4) {
        if (s=="" && k==4)  // note: condition to push result
            res.push_back(path.substr(1));
        return;
    } else {
        // note: leading zero
        // for example .010. is not true instead of .0.10. is true
        for (int i=1; i<=(s[0]=='0' ? 1:3) && i<=s.size(); ++i) {
            string x = s.substr(0, i);
            if (stoi(x) <= 255) 
                dfs(res, path+"."+x, s.substr(i), k+1);
        }
    }
}

vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    dfs(res, "", s, 0);
    return res;
}

int main(int argc, char** argv) {
    return 0;
}
