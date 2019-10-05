/*
 * created   : 2019-08-01 23:29:44
 * accepted  : 2019-08-01 23:55:52
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
  string a;
  cin >> a;
  int n = (int) a.size();
  auto check = [&](int md) {
    vector<vector<int>> ans;
    vector<int> cnt(26, 0);
    for (int i = 0; i < n; i++) {
      if (i < md) {
        cnt[a[i] - 'a']++;
      }
      else {
        ans.push_back(cnt);
        cnt[a[i - md] - 'a']--;
        cnt[a[i] - 'a']++;
      }
    }
    ans.push_back(cnt);
    trace(md, ans);
    int na = (int) ans.size();
    for (int i = 0; i < 26; i++) {
      int t = 0;
      for (int j = 0; j < na; j++) {
        if (ans[j][i] > 0) {
          t++;
        }
      }
      if (t == na) {
        return true;
      }
    }
    return false;
  };
  int lo = 0;
  int hi = n + 1;
  while (hi - lo > 1) {
    int md = lo + (hi - lo) / 2;
    if (check(md)) {
      hi = md;
    }
    else {
      lo = md;
    }
  }
  cout << hi << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
