//=============================================================
// Name        : 792b
// Date        : Fri Jun 28 17:27:16 CST 2019
// Accepted    : Fri Jun 28 18:17:00 CST 2019
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
  int n, k;
  cin >> n >> k;
  vector<int> a(k);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(n);
  iota(b.begin(), b.end(), 1);
  int cur = 0;
  vector<int> ans;
  for (int i = 0; i < k; ++i) {
    cur = (cur + a[i]) % sz(b);
    ans.push_back(b[cur]);
    b.erase(b.begin() + cur);
    if (cur == sz(b)) {
      cur = 0;
    }
  }
  for (int i = 0; i < k; ++i) {
    cout << ans[i] << (i == k - 1 ? "\n": " ");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
