#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (auto x:v)
        cout << x << " ";
    cout <<"] " << endl;
}

// Accepted
void setZeroes(vector<vector<int>>& A) {
    int m=A.size(), n=A[0].size();
    // extra space O(m+n)
    vector<bool> r(m, false);   // mark row
    vector<bool> c(n, false);   // mark column 
    for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j)
            if(A[i][j] == 0) {
                r[i] = true;
                c[j] = true;
            }
    for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j)
            if (r[i] || c[j])
                A[i][j] = 0;
    return;
}

// no extra space
void setZeroes(vector<vector<int>>& A) {
    int m=A.size(), n=A[0].size();
    bool col0 = false;
    for (int i=0; i<m; ++i) {
        if (A[i][0] == 0) col0 = true;
        for (int j=1; j<n; ++j)
            if(A[i][j] == 0) {
                A[i][0] = 0;
                A[0][j] = 0; 
            }
    }
    for (int i=m-1; i>=0; --i) {
        for (int j=n-1; j>=1; --j)
            if (A[i][0]==0 || A[0][j]==0) 
               A[i][j] = 0; 
        if(col0) A[i][0] = 0;
    }
    return;
}

int main(int argc, char** argv) {
    return 0;
}
