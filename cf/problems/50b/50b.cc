/* created   : 2020-03-09 19:10:38
 * accepted  : 2020-03-09 19:15:40
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void solve() {
  string s; cin >> s;
  int n = s.size();
  unordered_map<char, ll> cnt;
  for (int i = 0; i < n; i++) {
    cnt[s[i]]++;
  }
  ll ans = 0;
  for (auto it : cnt) {
    if (it.y >= 2) {
      ans += it.y * (it.y - 1);
    }
  }
  ans += n;
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
