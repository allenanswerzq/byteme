/* created   : 2019-08-18 16:01:28
 * accepted  : 2019-08-18 16:06:39
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 1 << 30;
  vector<int> p(k);
  iota(p.begin(), p.end(), 0);
  do {
    vector<string> b = a;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
      string t = b[i];
      for (int j = 0; j < k; j++) {
        t[j] = b[i][p[j]];
      }
      x[i] = stoi(t);
    }
    int cur = *max_element(x.begin(), x.end());
    cur -= *min_element(x.begin(), x.end());
    ans = min(ans, cur);
  } while (next_permutation(p.begin(), p.end()));
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
