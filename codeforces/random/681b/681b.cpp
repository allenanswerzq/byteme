//=============================================================
// Name        : 681b
// Date        : Sun Jun  9 09:14:12 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//=============================================================
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define sz(x) ((int)(x).size())
#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;

void solve() {
  ll n;
  cin >> n;
  const int maxn = 1e3;
  for (int a = 0; a < maxn; ++a) {
    for (int b = 0; b < maxn; ++b) {
      ll pt = a * 1ll * 1234567 + b * 1ll * 123456;
      if (n - pt >= 0 && (n - pt) % 1234 == 0) {
        trace(a, b);
        cout << "YES" << "\n";
        return;
      }
    }
  }
  cout << "NO" << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
