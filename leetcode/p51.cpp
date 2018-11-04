#include<bits/stdc++.h>using namespace std;

class Solution {
public:
  bool isValid(vector<string>& board, int x, int y) {
    int n = board.size();

    // Check row
    for (int i = 0; i < n; i++) 
      if (i != y && board[x][i] == 'Q') return 0;

    // Check cloumn
    for (int i = 0; i < n; ++i) 
      if (i != x && board[i][y] == 'Q') return 0;

    // Check left branch
    int i = x, j = y;
    while (i + 1 < n && j - 1 >= 0) {
      if (board[i + 1][j - 1] == 'Q') return 0;
      i++;
      j--;
    }

    i = x, j = y;
    while (i - 1 >= 0 && j + 1 < n) {
      if (board[i - 1][j + 1] == 'Q') return 0;
      i--;
      j++;
    }

    // Check right branch
    i = x, j = y;
    while (i + 1 < n && j + 1 < n) {
      if (board[i + 1][j + 1] == 'Q') return 0;
      i++;
      j++;
    }
    
    i = x, j = y;
    while (i - 1 >= 0 && j - 1 >= 0) {
      if (board[i - 1][j - 1] == 'Q') return 0;
      i--;
      j--;
    }

    return true;
  }

  void bt(int x, vector<string>& board, vector<vector<string>>& res) {
    int n = board.size();
    if (x == n) {
      res.push_back(board);
      return ;
    }

    for (int col = 0; col != n; ++col)
      if (isValid(board, x, col)) {
        board[x][col] = 'Q';
        bt(x+1, board, res);
        board[x][col] = '.';
      }
  }

  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    string ss;
    for (int i = 0; i < n; ++i) 
      ss += '.';
    vector<string> board(n, ss);
    bt(0, board, res); 
    return res;
  }
};

int main() {
  return 0;
}
