//=============================================================
// Name        : 1037b
// Date        : Thu Jun  6 20:56:01 CST 2019
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
  int n, s;
  cin >> n >> s;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  ll ans = 0;
  if (s > a[n / 2]) {
    for (int i = n / 2; i < n; ++i) {
      if (a[i] < s) {
        ans += s - a[i];
      }
    }
  } else if (s < a[n / 2]) {
    for (int i = n / 2; i >= 0; --i) {
      if (a[i] > s) {
        ans += a[i] - s;
      }
    }
  } else {
    ans = 0;
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
