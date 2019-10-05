//=============================================================
// Name        : 1029a
// Date        : Thu Jun  6 16:36:06 CST 2019
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

vector<int> z_function(string s) {
  int n = (int) s.length();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r) {
      z[i] = min(r - i + 1, z[i - l]);
    }
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      ++z[i];
    }
    if (i + z[i] - 1 > r) {
      l = i, r = i + z[i] - 1;
    }
  }
  return z;
}

void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> z = z_function(s);
  string pt = s;
  for (int i = 1; i < n; ++i) {
    if (z[i] == n - i) {
      pt = s.substr(z[i]);
      break;
    }
  }
  trace(z, pt);
  string ans = s;
  for (int i = 0; i < k - 1; ++i) {
    ans += pt;
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
