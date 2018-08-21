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


bool check(ll inp) {
  string s = to_string(inp);
  // trace(s);
  fori (i, 0, sz(s))
    if ((s[i]-'0') % 2)
      return 0;
  return 1;
}

ll solve(ll inp) {
  if (check(inp)) return 0; 
  int res = 0;
  fori (i, 1, inf)
    if (check(inp + i)) {
      // trace(inp + 1);
      res = i;
      break;
    }

  ford (i, -1, nnf)
    if (check(inp + i)) {
      res = min(res, abs(i));
      break;
    }
  return res;
}

// TODO large dataset.

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

  freopen("in.txt", "rt", stdin);
  clock_t begin = clock();

  int t; cin >> t;
  fori (i, 0, t) {
    ll a; cin >> a; 
    ll r = solve(a);
    cout << "Case #" << i + 1 << ": " << r << endl;
  }

  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cerr << "Elapsed: " << elapsed;
  return 0;
}
