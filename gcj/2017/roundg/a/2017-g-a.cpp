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


ull modpow(ull p, ull n, ull m) {
  ull w = 1;
  for (ull i = 1ULL << (sizeof(ull)*8-1); i != 0; i >>= 1) {
    if ((n & i) == 0) {
      w *= w;
    } else {
      w *= w * p;
    }
    w %= m;
  }
  return w;
}

ll solve(int a, int n, int p) {
  ll res = a % p;
  fori (i, 1, n + 1) {
    res = modpow(res, i, p); 
  }
  return res;
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

  freopen("2017-g-a-SSSSSSmall.txt", "rt", stdin);
  clock_t begin = clock();

  int t; cin >> t;
  fori (i, 1, t + 1) {
    int a, n, p; cin >> a >> n >> p;
    ll r = solve(a, n, p);
    output(i, r);
  }

  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cerr << "Elapsed: " << elapsed;
  return 0;
}
