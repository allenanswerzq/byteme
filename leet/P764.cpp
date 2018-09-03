#include<bits/stdc++.h>
using namespace std;


const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

class Solution {
public:
  int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
      vector<vector<int>> matrix(N, vector<int>(N, 1));       
      for (auto m: mines)
        matrix[m[0]][m[1]] = 0;

      vector<vector<int>> left(N, vector<int>(N, 0));
      auto right=left, up=left, down=left;
      for (int i=0; i<N; ++i) 
        for (int j=0; j<N; ++j) {
          if (matrix[i][j] == 1) {
            left[i][j] = j==0 ? 1: left[i][j-1]+1;  
            up[i][j]   = i==0 ? 1: up[i-1][j]+1;
          }
        } 

      int ret = 0;
      for (int i=N-1; i>=0; i--)
        for (int j=N-1; j>=0; j--) {
          if (matrix[i][j] == 1) {
            right[i][j] = j==N-1 ? 1: right[i][j+1]+1;  
            down[i][j] = i==N-1 ?  1: down[i+1][j]+1;
            ret = max(ret, min(min(left[i][j], right[i][j]), 
                               min(up[i][j], down[i][j])
                               ));
          }
        }
      return ret;
  }
};
