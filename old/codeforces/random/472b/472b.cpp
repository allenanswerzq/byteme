//=============================================================
// Name        : 472b
// Date        : Sat Jun  8 14:28:35 CST 2019
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
  int n, k;
  cin >> n >> k;
  const int maxn = 2000 + 7;
  vector<int> a(n), cnt(maxn);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  a.insert(a.begin(), 1);
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
  trace(a);
  int ans = 0, cur = n;
  for (int i = 0; i < (int) a.size() - 1; ++i) {
    cur = cur - cnt[a[i]];
    int time = (cur + k - 1) / k;
    ans += (2 * time - 1) * (a[i + 1] - a[i]);
  }
  cout << ans + (a.back() - 1) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
