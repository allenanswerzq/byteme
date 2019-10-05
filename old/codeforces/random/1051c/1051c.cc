/*
 * creat   : 2019-07-20 22:29:51
 * accept  : 2019-07-20 23:34:07
 * author  : landcold7
 */
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
  vector<int> cnt(120);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  int x = 0;
  string ans;
  ans.resize(n);
  for (int i = 0; i < n; ++i) {
    if (cnt[a[i]] == 1) {
      ans[i] = 'A' + x;
      x ^= 1;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (x == 1 && cnt[a[i]] > 2) {
      ans[i] = 'B';
      x = 0;
    }
  }
  if (x == 1) {
    cout << "NO" << "\n";
    return;
  }
  for (int i = 0; i < n; ++i) {
    if (ans[i] == 0) {
      ans[i] = 'A';
    }
  }
  cout << "YES" << "\n";
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
