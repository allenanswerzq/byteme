/* created   : 2020-04-10 22:18:04
 * accepted  : 2020-04-10 22:38:57
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  string s, t; cin >> s >> t;
  int n = s.size();
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }
  int lo = -1;
  int hi = n + 1;
  while (lo + 1 < hi) {
    int md = lo + (hi - lo) / 2;
    vector<bool> use(n);
    for (int i = 0; i < md; i++) {
      use[a[i]] = true;
    }
    int p = 0;
    for (int i = 0; i < n; i++) {
      if (!use[i] && s[i] == t[p]) {
        if (++p >= t.size()) {
          break;
        }
      }
    }
    trace(a, md, use, p);
    if (p >= t.size()) {
      lo = md;
    }
    else {
      hi = md;
    }
  }
  trace(lo, hi);
  cout << lo << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
