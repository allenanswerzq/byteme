#include <cstdio>  
#include <cmath>
#include <climits>
#include <cstdlib>
#include <ctype.h> // <cctype> isalpha isdigit
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>   // std:string std:stoi
#include <tuple>
#include <queue>
#include <deque>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (auto x:v)
        cout << x << " ";
    cout <<"] " << endl;
}

int result(vector<vector<int>> &M, int x, int y) {
    int m = M.size();
    int n = M[0].size();
    int row = x-1>=0 ? x-1 : 0;
    int col = y-1>=0 ? y-1:  0;
    int k = 0, sum = 0;
    for (int i=row; i<=x+1 && i<m; ++i)
        for (int j=col; j<=y+1 && j<n; ++j) {
            sum += M[i][j];
            ++k;
        }
    return sum / k; 
}

vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
    int m = M.size();
    int n = M[0].size();
    vector<vector<int>> res (m, vector<int>(n, 0));
    for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j) {
            res[i][j] = result(M, i, j);
        }
    return res; 
}

int main(int argc, char** argv) {
    return 0;
}
