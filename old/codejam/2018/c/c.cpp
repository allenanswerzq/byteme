#include<bits/stdc++.h>
using namespace std;


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

int main() {
 
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

  return 0;
}
