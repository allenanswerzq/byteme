#include<bits/stdc++.h>using namespace std;

#define uint unsigned int

class Solution {
public:
  bool isValidSudoku(vector<vector<char>>& board) {
    uint rows[9] = {0};
    uint cols[9] = {0};
    uint area[9] = {0};
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
        if (board[i][j] == '.') continue;
        int idx = board[i][j] - '0';
        int t = 1 << idx;
        if (rows[i] & t || cols[j] & t || area[i / 3 * 3 + j / 3] & t) 
          return 0;
        rows[i] |= t;
        cols[j] |= t;
        area[i / 3 * 3 + j / 3] |= t;
      }
    }
    return true;
  }
};

int main() {
  return 0;
}
