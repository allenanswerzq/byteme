/*
 * creat   : 2019-07-16 13:13:07
 * accept  : 2019-07-16 14:28:47
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
  if (k < __builtin_popcount(n)) {
    cout << "NO" << "\n";
    return;
  }
  deque<int> ans;
  for (int i = 0; i < 32; ++i) {
    if ((1 << i) & n) {
      ans.push_back((1 << i));
    }
  }
  trace(ans);
  while (sz(ans) < k && !ans.empty()) {
    trace(ans);
    int t = ans.back();
    ans.pop_back();
    if (t == 1) {
      break;
    }
    if (t / 2 == 1) {
      ans.push_front(t / 2);
      ans.push_front(t / 2);
    } else {
      ans.push_back(t / 2);
      ans.push_back(t / 2);
    }
  }
  sort(ans.begin(), ans.end());
  if (sz(ans) == k) {
    cout << "YES" << "\n";
    for (int i = 0; i < k; ++i) {
      cout << ans[i] << (i == k - 1 ? "\n" : " ");
    }
  }
  else {
    cout << "NO" << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
