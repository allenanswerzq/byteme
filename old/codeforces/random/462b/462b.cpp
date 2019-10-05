//=============================================================
// Name        : 462b
// Date        : Sat Jun  8 15:26:26 CST 2019
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
  string a;
  cin >> a;
  vector<int> cnt(26);
  for (int i = 0; i < n; ++i) {
    cnt[a[i] - 'A']++;
  }
  sort(cnt.rbegin(), cnt.rend());
  trace(cnt);
  ll ans = 0;
  for (int i = 0; i < 26; ++i) {
    if (k >= cnt[i]) {
      ans += cnt[i] * 1ll * cnt[i];
      k -= cnt[i];
    } else {
      ans += k * 1ll * k;
      break;
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
