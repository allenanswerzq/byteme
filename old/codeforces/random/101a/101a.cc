//=============================================================
// Name        : 101a
// Date        : Thu Jul  4 21:14:32 CST 2019
// Accepted    : Thu Jul  4 21:47:23 CST 2019
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
  string a;
  cin >> a;
  int k;
  cin >> k;
  vector<pair<int, char>> cnt(26);
  for (int i = 0; i < sz(a); ++i) {
    cnt[a[i] - 'a'].x++;
    cnt[a[i] - 'a'].y = a[i];
  }
  sort(cnt.begin(), cnt.end());
  for (int i = 0; i < 26; ++i) {
    if (cnt[i].x > 0 && k > 0) {
      int mi = min(cnt[i].x, k);
      k -= mi;
      cnt[i].x -= mi;
    }
  }
  int ans = 0;
  for (int i = 0; i < 26; ++i) {
    ans += (cnt[i].x > 0);
  }
  string ret;
  for (int i = 0; i < sz(a); ++i) {
    for (int j = 0; j < 26; ++j) {
      if (cnt[j].x > 0 && cnt[j].y == a[i]) {
        cnt[j].x--;
        ret += cnt[j].y;
        break;
      }
    }
  }
  cout << ans << "\n";
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
