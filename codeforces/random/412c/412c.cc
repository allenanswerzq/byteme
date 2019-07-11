//=============================================================
// Name        : 412c
// Date        : Fri Jul  5 23:00:34 CST 2019
// Accepted    : Fri Jul  5 23:14:18 CST 2019
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
  string s;
  cin >> s;
  vector<set<char>> a(sz(s));
  for (int i = 0; i < sz(s); ++i) {
    a[i].insert(s[i]);
  }
  for (int i = 0; i < n - 1; ++i) {
    cin >> s;
    for (int j = 0; j < sz(s); ++j) {
      if (!a[j].count(s[j])) {
        a[j].insert(s[j]);
      }
    }
  }
  trace(a);
  string ans;
  for (int i = 0; i < sz(s); ++i) {
    if (sz(a[i]) == 1) {
      if (*a[i].begin() == '?') {
        ans += 'c';
      }
      else {
        ans += *a[i].begin();
      }
    }
    else if (sz(a[i]) == 2 && a[i].count('?')) {
      for (auto t : a[i]) {
        if (t != '?') {
          ans += t;
          break;
        }
      }
    }
    else {
      ans += '?';
    }
  }
  cout << ans << "\n";
}

void solve2() {
  int n;
  cin >> n;
  const int maxn = 1100;
  string ans(maxn, '*');
  int sa;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    sa = sz(s);
    for (int j = 0; j < sa; ++j) {
      if (s[j] != '?') {
        if (ans[j] == '*') {
          ans[j] = s[j];
        }
        else if (ans[j] != s[j]) {
          ans[j] = '?';
        }
      }
    }
  }
  for (int i = 0; i < sa; ++i) {
    cout << (ans[i] == '*' ? 'a' : ans[i]) << (i == sa - 1 ? "\n" : "");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
