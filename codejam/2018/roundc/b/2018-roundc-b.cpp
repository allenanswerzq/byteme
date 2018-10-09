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

# Only small data works.

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

  freopen("2018-roundc-b-small.txt", "rt", stdin);
  clock_t begin = clock();

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


  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cerr << "Elapsed: " << elapsed;
  return 0;
}
