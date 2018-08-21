#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (int x:v)
            cout << x << " ";
    cout <<"] " << endl;
}

// NOTE: difference between pointer vs reference
// http://www.embedded.com/electronics-blogs/programming-pointers/4023307/References-vs-Pointers
void bt(vector<int>& A, int target, vector<int>& ans, vector<vector<int>>& ret, int start) {
    if (target == 0) {
		ret.push_back(ans);
    }else {
        for (int i=start; i<A.size() && target>=A[i]; ++i) {
           ans.push_back(A[i]);
           bt(A, target-A[i], ans, ret, i);     
           ans.pop_back();
        }
   }
}
vector<vector<int>> combinationSum(vector<int>& A, int target) {
    sort(A.being(), A.end());
    vector<vector<int>> ret;
    vector<int> ans;
    bt(A, target, ans, ret, 0);    
    return ret;
}

int main(int argc, char** argv) {
    //NOTE: How set works
    int n[] = {1, 2};
    vector<int> v(n, n+2);

    set<vector<int>> s;
    s.insert(v);
    s.insert(v);
    s.insert({3, 4})
    for (auto vv: s) {
        printVector(vv);
    }

    // int target = 4;
    // if (argc > 1)
    //     target = atoi(argv[1]);
    // vector<vector<int>> ret = combinationSum(v, target); 
    // cout << "[" << endl;
    // for (auto v: ret)
    //     printVector(v);
    // cout << "]" << endl;
    return 0;
}
