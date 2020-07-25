/* created   : 2020-03-14 00:19:52
 * accepted  : 2020-03-14 18:35:47
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
typedef pair<int, int> pii;

void solve() {
  int n; cin >> n;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  string t; cin >> t;
  int nt = t.size();
  int p = 0;
  int i = 0;
  for (; i <= n; i++) {
    while (p < nt && t[p] != '<') {
      p++;
    }
    if (p >= nt) break;
    while (p < nt && t[p] != '3') {
      p++;
    }
    if (p >= nt) break;
    if (i == n) {
      continue;
    }
    int j = 0;
    for (; j < (int) a[i].size(); j++) {
      while (p < nt && t[p] != a[i][j]) {
        p++;
      }
      if (p >= nt) break;
      p++;
    }
    if (j < (int) a[i].size()) {
      break;
    }
  }
  cout << (i <= n ? "no" : "yes") << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
