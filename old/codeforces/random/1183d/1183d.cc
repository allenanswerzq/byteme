/*
 * creat   : 2019-07-16 14:41:52
 * accept  : 2019-07-16 15:10:28
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
  vector<int> cnt(n + 7);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  ll ans = 0;
  int cur = (1 << 30);
  sort(cnt.begin(), cnt.end(), greater<int>());
  for (int i = 0; i < n + 7 && cnt[i] > 0; ++i) {
    int mi = max(min(cur, cnt[i]), 0);
    ans += mi;
    cur = mi - 1;
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    solve();
  }
  return 0;
}
