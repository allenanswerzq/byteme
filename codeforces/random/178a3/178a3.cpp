//=============================================================
// Name        : 178a3
// Date        : Wed Jun  5 09:56:56 CST 2019
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
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  // for (int i = 1; i <= n; ++i) {
  //   for (int t = 0; i + (1 << t) <= n; ++t) {
  //     trace(i, t, i + (1 << t));
  //   }
  // }
  trace(a);
  vector<ll> ret(n + 1);
  for (int i = 1; i <= n - 1; ++i) {
    int t = 0;
    while (i + (1 << t) <= n) {
      t++;
    }
    t--;
    // trace(i, t, i + (1 << t));
    if (a[i] == 0) {
      ret[i] = ret[i - 1];
    } else {
      ret[i] = ret[i - 1] + a[i];
      a[i + (1 << t)] += a[i];
    }
    cout << ret[i] << (i == n - 1 ? "\n" : " ");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
