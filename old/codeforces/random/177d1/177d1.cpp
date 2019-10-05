//=============================================================
// Name        : 177d1
// Date        : Tue Jun  4 19:42:20 CST 2019
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
  int n, m, c;
  cin >> n >> m >> c;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<ll> pr(m + 1);
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    pr[i + 1] = (pr[i] + x) % c;
  }
  for (int i = 0; i < n; ++i) {
    int hi = min(m - 1, i);
    int lo = max(0, i - (n - m));
    a[i] += (pr[hi + 1] - pr[lo] + c) % c;
    a[i] %= c;
    cout << a[i] << (i == n - 1 ? "\n" : " ");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
