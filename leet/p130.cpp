#include<bits/stdc++.h>
using namespace std;



template <typename T>
void _f(const char* name, T&& arg) {
  cout << name << ": " << arg << endl;
}

template <typename T, typename... Args> 
void _f(const char* names, T&& arg, Args&&... args) {
  const char* split = strchr(names + 1, ','); 
  cout.write(names, split - names) << ": " << arg << " |";
  _f(split, args...); 
} 

void dfs(vector<vector<char>>& board, int x, int y, char aa, char bb) {
  int r = sz(board), c = sz(board[0]);
  if (!(0<=x && x<r && 0<=y && y<c)) return;
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
  // Step1: replace all 'O' with '#'
  char aa = '#', bb = 'O';
  int rr = sz(board); 
  if (rr <= 0) return;
  int cc = sz(board[0]);
  fori (i, 0, rr)
    fori (j, 0, cc)
    if (board[i][j] == bb) 
      board[i][j] = aa; 

  // Left side edge
  fori (i, 0, rr)
    if (board[i][0] == aa)
    dfs(board, i, 0, aa, bb);
  // Right side edge
  fori (i, 0, rr)
    if (board[i][cc-1] == aa)
    dfs(board, i, cc-1, aa, bb);
  // Top side edge
  fori (i, 0, cc)
    if (board[0][i] == aa)
    dfs(board, 0, i, aa, bb);
  // Bottom side edge
  fori (i, 0, cc) 
    if (board[rr-1][i] == aa)
    dfs(board, rr-1, i, aa, bb);

  // Step3: replace all '#' with 'X'
  fori (i,  0, rr)
    fori (j, 0, cc) 
    if (board[i][j] == aa)
      board[i][j] = 'X';

  }
};




int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

  freopen("p130-IIIIIIIIIN.txt", "rt", stdin);
  clock_t begin = clock();


  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cerr << "Elapsed: " << elapsed;
  return 0;
}
