//=============================================================
// Name        : 23a
// Date        : Mon Jun  3 15:19:01 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//=============================================================
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define sz(x) ((int)(x).size())

#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;
typedef vector<int> vi;

void solve() {
  string s;
  cin >> s;
  int n = sz(s);
  int ret = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = n - 1; j >= i; --j) {
      string t = s.substr(i, j - i + 1);
      int cnt = 0;
      for (int k = i; k < n; ++k) {
        if (s.substr(k, sz(t)) == t) {
          cnt++;
        }
      }
      if (cnt >= 2) {
        ret = max(ret, j - i + 1);
      }
    }
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
