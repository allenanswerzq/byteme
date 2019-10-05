/*
 * created   : 2019-08-05 23:31:47
 * accepted  : 2019-08-05 23:46:08
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  string ans;
  int t = k;
  for (int i = 0; i < n; i++) {
    int mx = 0;
    char p = 'a';
    for (char c = 'a'; c <= 'z'; c++) {
      if (abs(c - s[i]) > mx) {
        mx = abs(c - s[i]);
        p = c;
      }
    }
    if (t >= mx) {
      t -= mx;
      ans += p;
    }
    else {
      for (char c = 'a'; c <= 'z'; c++) {
        if (abs(c - s[i]) == t) {
          p = c;
          break;
        }
      }
      t -= abs(p - s[i]);
      ans += p;
    }
  }
  if (t > 0) {
    cout << -1 << "\n";
    return;
  }
  int v = 0;
  for (int i = 0; i < n; i++) {
    v += abs(s[i] - ans[i]);
  }
  assert(v == k);
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
