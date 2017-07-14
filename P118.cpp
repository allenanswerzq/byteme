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
#include <queue>
#include <deque>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (auto x:v)
        cout << x << " ";
    cout <<"] " << endl;
}

// Accepted
vector<vector<int>> generate(int n) {
    vector<vector<int>> res;
    if (n >= 1) {
         res.push_back(vector<int> ({1}));
    }

    if (n >= 2) {
        res.push_back(vector<int> ({1, 1}));
    } 

    for (int i=2; i<n; ++i) {
        vector<int> ans;
        vector<int> tmp = res[i-1];
        for (int k=0; k<tmp.size()-1; ++k) {
            ans.push_back(tmp[k]+tmp[k+1]);
        }
        ans.push_back(1);
        ans.insert(ans.begin(), 1);
        res.push_back(ans);
    }
    return res;
}

int main(int argc, char** argv) {
    return 0;
}
