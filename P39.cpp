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

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (int x:v)
            cout << x << " ";
    cout <<"] " << endl;
}

// NOTE: difference between pointer vs reference
// http://www.embedded.com/electronics-blogs/programming-pointers/4023307/References-vs-Pointers
void bt1(vector<int>& A, int target, vector<int> ans, set<vector<int>>& ret) {
    if (target <= 0) {
        if (target == 0){
            sort(ans.begin(), ans.end());
            ret.insert(ans);
        }else return;
    }else {
        for (auto x: A) {
           ans.push_back(x);
           bt1(A, target-x, ans, ret);     
           ans.pop_back();
        }
   }
}

// more effective approach without use set
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
    vector<vector<int>> ret;
    vector<int> ans;
    bt(A, target, ans, ret, 0);    
    return ret;
}

int main(int argc, char** argv) {
    //NOTE: How set works
    //set<vector<int>> s;
    int n[] = {1, 2};
    vector<int> v(n, n+2);

    /*s.insert(v);
    s.insert(v);
    for (auto vv: s) {
        printVector(vv);
    }
    */
    int target = 4;
    if (argc > 1)
        target = atoi(argv[1]);
    vector<vector<int>> ret = combinationSum(v, target); 
    cout << "[" << endl;
    for (auto v: ret)
        printVector(v);
    cout << "]" << endl;
    return 0;
}
