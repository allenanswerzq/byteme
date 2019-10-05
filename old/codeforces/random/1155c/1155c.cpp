//=============================================================
// Name        : 1155c
// Date        : Sun Jun 16 10:51:31 CST 2019
// Accepted    : Sun Jun 16 11:32:07 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//=============================================================
#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x).size())
#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;

ll gcd(ll a, ll b) {
  if (a < b) {
    swap(a, b);
  }
  return b == 0 ? a : gcd(b, a % b);
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<ll> a(n);
  vector<ll> d(n - 1);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (i > 0) {
      d[i - 1] = a[i] - a[i - 1];
    }
  }
  trace(d);
  ll g = d[0];
  for (int i = 0; i < n - 1; ++i) {
    g = gcd(g, d[i]);
  }
  ll p = -1;
  for (int i = 0; i < m; ++i) {
    ll x;
    cin >> x;
    if (g % x == 0) {
      p = i;
      break;
    }
  }
  if (p == -1) {
    cout << "NO" << "\n";
    return;
  }
  cout << "YES" << "\n";
  cout << a[0] << " " << p + 1 << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
