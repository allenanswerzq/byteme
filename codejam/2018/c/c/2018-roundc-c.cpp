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


const int mod = 1e9 + 7;
vl build(ll n, ll x1, ll y1, ll c, ll d, ll e1, ll e2, ll f) {
  vl res;
  ll r = (x1 + y1) % f;
  res.pb(r);
  fori (i, 1, n) {
    ll x = (c * x1 + d * y1 + e1) % f;
    ll y = (d * x1 + c * y1 + e2) % f;
    ll r = (x + y) % f;
    res.pb(r);
    x1 = x; y1 = y;
  }
  // pvi(res);
  return res;
}

vl inp;

// TODO
ll solve(ll kk) { 
  int n = sz(inp);
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

  freopen("2018-roundc-c-SSSSSSmall.txt", "rt", stdin);
  clock_t begin = clock();

  int t; cin >> t;
  fori (i, 1, t + 1) {
    inp.clear();
    ll n, k, x1, y1, c, d, e1, e2, f;
    cin >> n >> k >> x1 >> y1 >> c >> d >> e1 >> e2 >> f;
    // trace( n,  k, x1,  y1,  c,  d,  e1,  e2,  f);
    inp = build( n,  x1,  y1,  c,  d,  e1,  e2,  f);
    ll r = solve(k); 
    output(i, r);
  }


  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cerr << "Elapsed: " << elapsed;
  return 0;
}
