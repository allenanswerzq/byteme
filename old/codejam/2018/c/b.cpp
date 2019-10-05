#include<bits/stdc++.h>
using namespace std;

bool check(vi a, vi b, vi c) {
  uset<int> st;
  vi vals = {a[0], a[1], b[0], b[1], c[0], c[1]};
  fora (v, vals) {
    if (st.count(v)) return 0;
    st.insert(v);
  }
  int x, y, z;
  x = a[2], y = b[2], z = c[2];
  // trace(x, y, z);
  return (x + y > z) && (x - y < z) &&
         (x + z > y) && (x - z < y) &&
         (y + z > x) && (y - z < x); 
}

const int size = 18;
int grid[size][size];
vvi edges;

int solve(int n) {
  fori (i, 0, n) {
    fori (j, i + 1, n) {
      if (grid[i][j])
        edges.pb({i, j, grid[i][j]});
    }
  }

  int m = sz(edges);
  int res = 0;
  fori (i, 0, m)
    fori (j, i + 1, m)
      fori (k, j + 1, m) {
        if (check(edges[i], edges[j], edges[k])) {
          // trace(m, i, j, k);
          // trace(edges[i][0], edges[i][1], edges[i][2]);
          // trace(edges[j][0], edges[j][1], edges[j][2]);
          // trace(edges[k][0], edges[k][1], edges[k][2]);
          ++res;
        }
      }
  return res;
}

// Only small data works.

int main() {
 
  int t; cin >> t;
  // t = 2;
  fori (i, 1, t + 1) {
    mst(grid, 0);
    edges.clear();
    int n; cin >> n;
    fori (j, 0, n) 
      fori (k, 0, n) {
        int a; cin >> a;
        grid[j][k] = a;
      }
    int r = solve(n);
    output(i, r);
  } 

  return 0;
}
