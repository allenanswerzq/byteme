#include<bits/stdc++.h>
using namespace std;

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

int main() {
 
  int t; cin >> t;
  fori (i, 1, t + 1) {
    int a, n, p; cin >> a >> n >> p;
    ll r = solve(a, n, p);
    output(i, r);
  }

  return 0;
}
