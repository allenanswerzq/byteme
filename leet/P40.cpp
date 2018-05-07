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

void bt(vector<int>& A, int target, vector<int>& ans, vector<vector<int>>& ret, int start) {
    if (target == 0) {
		ret.push_back(ans);
    }else {
        for (int i=start; i<A.size() && target>=A[i]; ++i) {
		   if (i>start && A[i] == A[i-1]) continue;
           ans.push_back(A[i]);
           bt(A, target-A[i], ans, ret, i+1);     
           ans.pop_back();
        }
   }
}
vector<vector<int>> combinationSum(vector<int>& A, int target) {
    vector<vector<int>> ret;
    vector<int> ans;
	sort(A.begin(), A.end());
    bt(A, target, ans, ret, 0);    
    return ret;
}

int main(int argc, char** argv) {
    int n[] = {10, 1, 2, 7, 6, 1, 5};
    vector<int> v(n, n+7);
    int target = 8;
    if (argc > 1)
        target = atoi(argv[1]);
    vector<vector<int>> ret = combinationSum(v, target); 
    cout << "[" << endl;
    for (auto v: ret)
        printVector(v);
    cout << "]" << endl;
    return 0;
}
