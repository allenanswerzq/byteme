#include<bits/stdc++.h>
using namespace std;

        fori(i, 0, n) \
          fori(j, 0, m) \
            fori(k, 0, c) \
              x[i][j][k] = v
const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

class WeirdRooks {
public:
  int board[10][10]; 
  int visit[10][10];
  int r;
  set<int> cnts;
  vi cols;
  string res;
  int check() {
    int res = 0;
    fori(i, 0, r)
      fori(j, 0, cols[i]) {
        if (board[i][j]) continue;
        int rr = 0;
        fori(k, i, r)
          if (board[k][j] != 0) {rr = 1; break;}
        if (rr) continue;
        rr = 0;
        // Check column
        fori(k, j, cols[i])
          if (board[i][k] != 0) {rr =1; break;}
        if (rr) continue;
        res++;
      }
    return res;
  }

  void mk_board() {
    int n = sz(cols);
    fori(i, 0, n) 
      fori(j, 0, cols[i]) {
        board[i][j] = 0;
        visit[i][j] = 0;
      }
  }

  int go(int n, int idx) {
    if (idx == n) {
      int x = check();
      return x;
    }
    int cnt = 0;
    fori(i, 0, r)
      fori(j, 0, 10) {

        if (board[i][j] == -1) continue;

        // Note: read the problem statement carefully.
        // No two rooks can share a row or column.
        int f = 0;
        fori(k, 0, r)
          if (board[k][j] == 2) {f = 1; break;}
        if (f) continue;
        
        f = 0;
        fori(k, 0, 10)
          if (board[i][k] == 2) {f = 1; break;}
        if (f) continue;

        if(!visit[i][j]) {
          visit[i][j] = 1;
          board[i][j] = 2;
          cnt = go(n, idx+1);
          cnts.insert(cnt);
          visit[i][j] = 0;
          board[i][j] = 0;
        }
      }
    return cnt;
  }

  string describe(vi aa) {
    cols = aa;
    res = "";
    r = sz(aa);
    mst2(board, 10, 10, -1);
    mst2(visit, 10, 10, 1);
    mk_board();
    int sum = 0;
    fora(c, cols)
      sum += c;
    // Note: since no two rooks can share a rwo or column,
    // so when the number of rooks exceed row number, the number of 
    // special rooks decrease.
    fori(n, 1, r+1) {
      // Put n rooks into board
      go(n, 0);
      fora(cnt, cnts)
        res += to_string(n) + "," + to_string(cnt) + " ";
      cnts.clear();
    }

    res = "0," + to_string(sum) + " " + res;
    return res.substr(0, sz(res)-1); 
  }
};

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  WeirdRooks go;
  vi aa = {3, 3, 3};
  cout << go.describe(aa) << '\n';
  aa = {1, 2, 3};
  cout << go.describe(aa) << '\n';
  aa = {1},
  cout << go.describe(aa) << '\n';
  aa = {2, 9};
  cout << go.describe(aa) << '\n';
  return 0;
}
