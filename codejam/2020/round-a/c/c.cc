/* created   : 2020-03-22 12:31:14
 * accepted  : 2020-03-22 12:35:38
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
#define debugstream ostream
#endif
typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  int n, k; cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  auto check = [&](int x) {
    int cnt = 0;
    for (int i = 0; i + 1 < n; i++) {
      cnt += (a[i + 1] - a[i] + x - 1) / x - 1;
    }
    return cnt <= k;
  };
  int lo = 1;
  int hi = 1e9 + 7;
  while (lo + 1 < hi) {
    int md = lo + (hi - lo) / 2;
    if (check(md)) {
      hi = md;
    }
    else {
      lo = md;
    }
  }
  cout << (check(lo) ? lo : hi) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
