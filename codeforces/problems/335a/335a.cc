/* created   : 2020-03-30 23:18:27
 * accepted  : 2020-03-31 00:19:48
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  string s; cin >> s;
  int n; cin >> n;
  map<char, int> mp;
  char ch = 'a';
  for (int i = 0; i < s.size(); i++) {
    mp[s[i]]++;
    ch = s[i];
  }
  trace(mp);
  if (n < mp.size()) {
    cout << -1 << '\n';
    return;
  }
  auto check = [&](int md) {
    int sheet_length = 0;
    for (auto it : mp) {
        sheet_length += (it.y + md - 1) / md;
    }
    return sheet_length <= n;
  };
  int lo = 1;
  int hi = 1200;
  while (lo + 1 < hi) {
    int md = lo + (hi - lo) / 2;
    if (check(md)) {
      hi = md;
    }
    else {
      lo = md;
    }
  }
  int ans = check(lo) ? lo : hi;
  cout << ans << '\n';
  string sheet;
  for (auto it : mp) {
    int t = (it.y + ans - 1) / ans;
    sheet += string(t, it.x);
  }
  if (sheet.size() < n) {
    string tmp = string(n - sheet.size(), ch);
    sheet += tmp;
  }
  cout << sheet << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
