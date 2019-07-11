//=============================================================
// Name        : 236b
// Date        : Sun Jun 23 10:34:28 CST 2019
// Accepted    : Sun Jun 23 11:29:32 CST 2019
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

const int mod = 1073741824;

int d(int x) {
  int ans = 0;
  for (int i = 1; i * i <= x; ++i) {
    if (x % i == 0) {
      ans++;
      if (x / i != i) {
        ans++;
      }
    }
  }
  return ans;
}

inline void add(int& a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  int mx = a * b * c;
  vector<int> cnt(mx + 7);
  // nlogn = 10^6 * 20
  for (int i = 1; i <= mx; ++i) {
    for (int j = i; j <= mx; j += i) {
      cnt[j]++;
    }
  }
  // trace(cnt);
  int ans = 0;
  for (int i = 1; i <= a; ++i) {
    for (int j = 1; j <= b; ++j) {
      for (int k = 1; k <= c; ++k) {
        add(ans, cnt[i * j * k]);
      }
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
