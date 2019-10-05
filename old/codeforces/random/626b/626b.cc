//=============================================================
// Name        : 626b
// Date        : Tue Jun 25 10:13:43 CST 2019
// Accepted    : Tue Jun 25 10:50:14 CST 2019
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

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  string t = "BGR";
  vector<int> cnt(3);
  for (int i = 0; i < n; ++i) {
    cnt[t.find(s[i])]++;
  }
  trace(cnt);
  int z = 0;
  for (int i = 0; i < 3; ++i) {
    z += (cnt[i] == 0);
  }
  vector<int> ans(3);
  if (z == 0) {
    fill(ans.begin(), ans.end(), 1);
  }
  else if (z == 2) {
    for (int i = 0; i < 3; ++i) {
      if (cnt[i] > 0) {
        ans[i] = 1;
      }
    }
  }
  else if (z == 1) {
    int sum = accumulate(cnt.begin(), cnt.end(), 0);
    for (int i = 0; i < 3; ++i) {
      ans[i] = (cnt[i] != sum - 1);
    }
  }
  else {
    assert(false);
  }
  for (int i = 0; i < 3; ++i) {
    if (ans[i]) {
      cout << t[i];
    }
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
