#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n, vector<int>(n, 0));
    int up = 0, down = n - 1, left = 0, right = n - 1;
    int k = 1;
    while (up <= down && left <= right) {
      for (int i = left; i <= right; ++i) res[up][i] = k++;
      for (int i = up + 1; i < down; ++i) res[i][right] = k++;  
      for (int i = right; i > left; --i) res[down][i] = k++;
      for (int i = down; i > up; --i) res[i][left] = k++;
      ++up, --down, ++left, --right;
    }
    return res;
  }
};

int main(int argc, char** argv) {
  return 0;
}
