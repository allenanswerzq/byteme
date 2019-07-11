/*
 * Name        : 39f
 * Creat       : Thu Jul 11 16:51:51 CST 2019
 * Accept      : Thu Jul 11 17:11:56 CST 2019
 * Author      : landcold7
 * Motivation  : Action speaks louder more than words
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
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(m);
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
  }
  vector<int> b(k);
  for (int i = 0; i < k; ++i) {
    cin >> b[i];
  }
  vector<int> cnt(m);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < k; ++j) {
      if (b[j] % a[i] == 0) {
        cnt[i]++;
      }
    }
  }
  vector<int> ans;
  int mi = *min_element(cnt.begin(), cnt.end());
  for (int i = 0; i < m; ++i) {
    if (cnt[i] == mi) {
      ans.push_back(i);
    }
  }
  cout << sz(ans) << "\n";
  for (int i = 0; i < sz(ans); ++i) {
    cout << ans[i] + 1 << (i == sz(ans) - 1 ? "\n" : " ");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
