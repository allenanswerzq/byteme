/* created   : 2020-04-10 22:43:17
 * accepted  : 2020-04-10 23:26:30
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
  vector<multiset<int>> st(26);
  for (int i = 0; i < s.size(); i++) {
    st[s[i] - 'a'].insert(i);
  }
  int m; cin >> m;
  for (int i = 0; i < m; i++) {
    int op; cin >> op;
    if (op == 1) {
      int x; char ch; cin >> x >> ch;
      x--;
      st[s[x] - 'a'].erase(x);
      st[ch - 'a'].insert(x);
      s[x] = ch;
    }
    else {
      int l, r; cin >> l >> r;
      l--, r--;
      int ans = 0;
      trace(s, l, r, st);
      for (int j = 0; j < 26; j++) {
        if (st[j].empty()) continue;
        auto it = st[j].lower_bound(l);
        if (it != st[j].end() && *it <= r) {
          ans++;
        }
      }
      cout << ans << '\n';
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
