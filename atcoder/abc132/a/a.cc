//=============================================================
// Name        : a
// Date        : Wed Jul  3 22:38:38 CST 2019
// Accepted    : Wed Jul  3 22:39:45 CST 2019
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
  string s;
  cin >> s;
  vector<int> cnt(26);
  for (int i = 0; i < sz(s); ++i) {
    cnt[s[i] - 'A']++;
  }
  int ans = 0;
  for (int i = 0; i < 26; ++i) {
    if (cnt[i] >= 2) {
      ans++;
    }
  }
  cout << (ans >= 2 ? "Yes" : "No") << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
