/*
 * creat   : 2019-07-19 21:37:18
 * accept  : 2019-07-20 00:03:27
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
  vector<int> a(n);
  map<int, int> mp;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    mp[a[i]]++;
  }
  auto check = [&](int x) {
    ll two = 1;
    int ans = 0;
    for (int i = 0; i < 33; ++i) {
      if (two > x) {
        int d = two - x;
        if (d != x && mp.count(d)) {
          ans |= 1;
        }
        else if (d == x && mp[d] > 1) {
          ans |= 1;
        }
      }
      two <<= 1;
    }
    return ans;
  };
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (!check(a[i])) {
      ans++;
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
