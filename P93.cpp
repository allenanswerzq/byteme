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
#include <string>   // std:string std:stoi

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (auto x:v)
        cout << x << " ";
    cout <<"] " << endl;
}

// Typical dfs problem
// very good solution but not by me
void dfs(vector<string>& res, string path, string s, int k) {
    if (s=="" || k==4) {
        if (s=="" && k==4)  // NOTE: condition to push result
            res.push_back(path.substr(1));
        return;
    } else {
        // NOTE: leading zero
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
