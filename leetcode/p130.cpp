#include<bits/stdc++.h>
using namespace std;

#define vc vector<char>
#define vvc vector<vc>

void dfs(vvc& board, int x, int y, char aa, char bb) {
  int r = sz(board), c = sz(board[0]);
  if (!(0 <= x && x < r && 0 <= y && y < c)) return;
  if (board[x][y] != aa) return ;

  board[x][y] = bb;
  dfs(board, x + 1, y, aa, bb);
  dfs(board, x - 1, y, aa, bb);
  dfs(board, x, y + 1, aa, bb);
  dfs(board, x, y - 1, aa, bb);
}

class Solution {
public:
  void solve(vector<vector<char>>& board) {
    int r = sz(board); 
    if (r <= 0) return;
    int c = sz(board[0]);

    // step1: replace all 'o' with '#'.
    char aa = '#', bb = 'o';
    fori (i, 0, r)
      fori (j, 0, c)
      if (board[i][j] == bb) 
        board[i][j] = aa; 

    // step2: replace all edge # with o.
    // left side edge
    fori (i, 0, r)
      if (board[i][0] == aa)
      dfs(board, i, 0, aa, bb);

    // right side edge
    fori (i, 0, r)
      if (board[i][c-1] == aa)
      dfs(board, i, c-1, aa, bb);

    // top side edge
    fori (i, 0, c)
      if (board[0][i] == aa)
      dfs(board, 0, i, aa, bb);

    // bottom side edge
    fori (i, 0, c) 
      if (board[r-1][i] == aa)
      dfs(board, r-1, i, aa, bb);

    // step3: replace all '#' with 'x'.
    fori (i,  0, r)
      fori (j, 0, c) 
        if (board[i][j] == aa)
          board[i][j] = 'x';
  }
};

int main() {
  return 0;
}
