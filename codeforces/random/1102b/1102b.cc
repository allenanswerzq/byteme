/*
 * creat   : 2019-07-19 14:56:39
 * accept  : 2019-07-19 15:38:28
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
  int n, k;
  cin >> n >> k;
  const int N = 5200;
  vector<int> cnt(N);
  vector<vector<int>> idx(N);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    cnt[x]++;
    idx[x].push_back(i);
  }
  int ok = 0;
  int col = 1;
  vector<int> ans(n);
  for (int i = 0; i < N; ++i) {
    if (cnt[i] > k) {
      cout << "NO" << "\n";
      return;
    }
    else {
      for (auto ix : idx[i]) {
        ans[ix] = col++;
        if (col > k) {
          ok = 1, col = 1;
        }
      }
    }
  }
  if (!ok) {
    cout << "NO" << "\n";
    return;
  }
  cout << "YES" << "\n";
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << (i == n - 1 ? "\n" : " ");
  }
}


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
