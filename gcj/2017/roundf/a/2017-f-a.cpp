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


bool solve(vi inp) {
  // pvi(inp);
  int n = sz(inp);
  if (n <= 2) return 1;
  int mid = (n - 1) / 2;
  // trace(mid, n);
  vi b, c;
  fori (i, 0, n) {
    if (i == mid) continue;
    if (inp[i] < inp[mid]) b.pb(inp[i]);
    else c.pb(inp[i]);
  }
  if (sz(b) == 0) {
    if (solve(c)) return 1;
  }
  else if(sz(c) == 0) {
    if (solve(b)) return 1;
  }
  // pvi(b);
  // pvi(c);
  return 0;
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

  freopen("2017-f-a-SSSSSSmall.txt", "rt", stdin);
  clock_t begin = clock();

  int t; cin >> t;
  fori (i, 1, t + 1) {
    int n; cin >> n;
    vi inp;
    fori (k, 0, n) {
      int a; cin >> a;
      inp.pb(a);
    }
    bool r = solve(inp);
    output(i, r ? "YES" : "NO");
  }


  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cerr << "Elapsed: " << elapsed;
  return 0;
}
