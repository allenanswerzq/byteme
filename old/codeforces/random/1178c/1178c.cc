//=============================================================
// Name        : 1178c
// Date        : Tue Jun 18 08:49:35 CST 2019
// Accepted    : Tue Jun 18 09:35:04 CST 2019
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
  vector<int> a(n);
  vector<int> ele = {4, 8, 15, 16, 23, 42};
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i] = find(ele.begin(), ele.end(), a[i]) - ele.begin();
  }
  trace(a);
  vector<int> cnt(6);
  for (int i = 0; i < n; ++i) {
    int v = a[i];
    bool ok = 1;
    for (int j = 0; j < v; ++j) {
      if (cnt[j] == 0 || cnt[v] >= cnt[j]) {
        ok = 0;
        break;
      }
    }
    if (ok) {
      cnt[v]++;
    }
  }
  int mi = *min_element(cnt.begin(), cnt.end());
  cout << (n - mi * 6) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
