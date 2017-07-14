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
vector<int> getRow(int n) {
    if (n == 0) return vector<int> ({1});
    vector<int> res(n+1, 1);
    vector<int> ans(n+1, 1);
    for (int i=2; i<n; ++i) {
        for (int k=0; k<i-1; ++k)
            ans[k+1] = res[k]+res[k+1]; 
        ans[0] = 1;
        ans[i] = 1;
        res = ans;
    }
    return res;
}

// more short solution
// best solution
vector<int> getRow(int n) {
    vector<int> A(n+1, 1);
    for (int i=1; i<=n; ++i) {
        for (int k=i-1; k>=1; --k)
            A[k] += A[k-1];
    }
    return A;
}

int main(int argc, char** argv) {
    return 0;
}
