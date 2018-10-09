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

const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}


int dp[32][32][1 << 6];
vvi dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vs grid;
int m, n;

class Solution {
public:
  
  int go(int sr, int sc) {
  int keys = 0;
  fori (i, 0, m) 
    fori (j, 0, n) {
    if ('a'<=grid[i][j] && grid[i][j]<='z') {
      keys |= 1 << (grid[i][j] - 'a');
    }
    }
  
  mst(dp, -1);
  dp[sr][sc][0] = 0;
  deque<int> que;
  que.pb((sr << 12) + (sc << 6) + 0); 
  while (sz(que)) {
    int status = que.fr(); que.ppf();
    int r = status >> 12;
    int c = (status >> 6) & 0x3f;
    int k = (status) & 0x3f;
    // trace(r, c, k, keys);
    fori (i, 0, 4) {
    int nr = r + dirs[i][0];
    int nc = c + dirs[i][1];
    if (!(0<=nr && nr<m && 0<=nc && nc<n)) continue;
    char ch = grid[nr][nc];
    if (ch == '#') continue;
    if ('A' <= ch && ch <= 'Z') {
      int x = 1 << (ch - 'A');
      if (!(k & x)) continue;
    }
    int nk = k;
    if ('a' <= ch && ch <= 'z')
      nk |= 1 << (ch - 'a');
    // trace(nr, nc, nk);
    if (dp[nr][nc][nk] < 0) {
      dp[nr][nc][nk] = dp[r][c][k] + 1;
      if (nk == keys) return dp[nr][nc][nk]; 
      que.pb((nr << 12) + (nc << 6) + nk);
    }
    }
  }
  return -1;
  } 

  int shortestPathAllKeys(vector<string>& g) {
  grid = g;
  m = sz(grid);
  if (m < 1) return -1;
  n = sz(grid[0]);
  fori (i, 0, m) {
    fori (j, 0, n) 
    if (grid[i][j] == '@')
      return go(i, j);
  }
  return -1;
  }
};

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

  freopen("p864-IIIIIIIIIN.txt", "rt", stdin);
  clock_t begin = clock();

  Solution go;
  vs aa = {"@.a.#","###.#","b.A.B"};
  cout << go.shortestPathAllKeys(aa) << endl;

  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cerr << "Elapsed: " << elapsed;
  return 0;
}
