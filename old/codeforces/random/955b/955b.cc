/*
 * created   : 2019-08-04 21:15:46
 * accepted  : 2019-08-04 21:30:49
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
  string s;
  cin >> s;
  vector<int> a(26);
  for (int i = 0; i < (int) s.size(); i++) {
    a[s[i] - 'a']++;
  }
  int cnt = 0;
  for (int i = 0; i < 26; i++) {
    if (a[i] > 0) {
      cnt++;
    }
  }
  bool ok = 0;
  if (cnt == 2) {
    int x = 0;
    for (int i = 0; i < 26; i++) {
      if (a[i] >= 2) {
        x++;
      }
    }
    if (x == 2) {
      ok = 1;
    }
  }
  else if (cnt == 3) {
    int x = 0;
    for (int i = 0; i < 26; i++) {
      if (a[i] >= 2) {
        x++;
      }
    }
    if (x >= 1) {
      ok = 1;
    }
  }
  else if (cnt == 4) {
    ok = 1;
  }
  else {
    ok = 0;
  }
  cout << (ok ? "Yes" : "No") << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
