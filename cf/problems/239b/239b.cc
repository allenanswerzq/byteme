/* created   : 2020-04-04 15:54:47
 * accepted  : 2020-04-04 18:44:19
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve(string t) {
  int cp = 0;
  int dp = 1;
  vector<int> ans(10);
  while (0 <= cp && cp < t.size()) {
    bool erase = false;
    if ('0' <= t[cp] && t[cp] <= '9') {
      ans[t[cp] - '0']++;
      t[cp]--;
      if (t[cp] < '0') {
        trace(t[cp]);
        erase = true;
      }
    }
    else {
      dp = (t[cp] == '<' ? -1 : 1);
      int next = cp + dp;
      if (next >= 0 && next < t.size() && (t[next] == '<' || t[next] == '>')) {
        erase = true;
      }
    }
    if (erase) {
      t.erase(cp, 1);
      if (dp == -1) {
        cp--;
      }
    }
    else {
      cp += dp;
    }
  }
  for (int i = 0; i < 10; i++) {
    cout << ans[i] << (i == 10 - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, q; cin >> n >> q;
  string s; cin >> s;
  for (int i = 0; i < q; i++) {
    int l, r; cin >> l >> r;
    l--, r--;
    string t = s.substr(l, r - l + 1);
    solve(t);
  }
  return 0;
}
