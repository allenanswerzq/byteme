#include<bits/stdc++.h>using namespace std;

class Solution {
public:
  bool isValid(vector<vector<char>>& board, int row, int col, char ch) {
    for (int i = 0; i < 9; ++i) {
      if (board[row][i] != '.' && board[row][i] == ch) return 0;
      if (board[i][col] != '.' && board[i][col] == ch) return 0;
      if (board[row / 3 * 3 + i / 3][col / 3 * 3 + i % 3] != '.' &&
        board[row / 3 * 3 + i / 3][col / 3 * 3 + i % 3] == ch) 
      return 0;
    }
    return 1;
  }

  bool bt(vector<vector<char>>& board) {
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        if (board[i][j] == '.') {
          for (char c = '1'; c <= '9'; ++c) {
            if (isValid(board, i, j, c)) {
              board[i][j] = c;
              if(bt(board)) return true;
            }
          }
          board[i][j] = '.';
          return false;
        }
      }
    }
    return true;
  }

  void solveSudoku(vector<vector<char>>& board) {
    bt(board);
  }
  
};

int main() {
  return 0;
}
