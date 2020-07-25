/* created   : 2020-02-10 22:34:45
 * accepted  : 2020-02-10 22:57:24
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

#define lowbit(x) (x) & (-x)

void solve() {
  const int N = 1e5 + 7;
  vector<int> a(N);
  for (int i = 1; i < N; i++) {
    a[i] = lowbit(i);
  }
  int sum, lim; cin >> sum >> lim;
  ll mx = 0;
  vector<pair<int, int>> v;
  for (int i = 1; i <= lim; i++) {
    mx += a[i];
    v.push_back({a[i], i});
  }
  if (sum > mx) {
    cout << -1 << '\n';
    return;
  }
  sort(all(v));
  reverse(all(v));
  trace(v);
  vector<int> ans;
  for (int i = 0; i < v.size(); i++) {
    if (sum == 0) {
      break;
    }
    if (sum >= v[i].x) {
      sum -= v[i].x;
      ans.push_back(v[i].y);
    }
  }
  trace(sum);
  assert(sum == 0);
  int n = ans.size();
  cout << n << '\n';
  for (int i = 0; i < n; i++) {
    cout << ans[i] << (i == n - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
