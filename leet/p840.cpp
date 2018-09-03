#include<bits/stdc++.h>
using namespace std;



const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

class Solution {
public:
  int numMagicSquaresInside(vector<vector<int>>& grid) {
  int h = sz(grid) - 3 + 1;
  int w = sz(grid[0]) - 3 + 1;
  int res = 0;
  fori(i, 0, h) {
  fori(j, 0, w) {
  
  // Valid numbers.
  int flag = 0;
  fori(k, i, i+3) {
    fori(n, j, j+3)
    if (! (1<=grid[k][n] && grid[k][n] <= 9)) {
    flag = 1;
    break;
    }
    cout << endl;
    if (flag == 1) break;
  }
  if (flag == 1) continue;

  // Row.
  int ans = 0;
  flag = 0;
  fori(k, i, i+3) {
    int sum = 0;
    fori(n, j, j+3) {
    sum += grid[k][n];
    }
    if (k > i && sum != ans) {
    flag = 1;
    break;
    }
    if (k == i) ans = sum;
  }
  if (flag) continue;

  // Column.
  flag = 0;
  fori(k, j, j+3) {
    int sum = 0;
    fori(n, i, i+3) 
    sum += grid[n][k];
    if (k > j && sum != ans) {
    flag = 1;
    break;
    }
  }
  if (flag) continue;

  // Diagonals.
  sum = 0;
  sum = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2];
  if (sum != ans) continue;
  int a, b;
  a = i, b = j + 2;
  sum = grid[a][b] + grid[a+1][b-1] + grid[a+2][b-2];
  if (sum != ans) continue;

  ++res; 

  cout << endl;
  }
  }
  return res;
  }
};

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
