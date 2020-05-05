/* created   : 2020-05-05 15:31:23
 * accepted  : 2020-05-05 17:19:56
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n, k; cin >> n >> k;
  vector<int> a(n);
  for (auto &x : a) {
    cin >> x;
  }
  vector<ll> ps(n + 1);
  sort(all(a));
  for (int i = 0; i < n; i++) {
    ps[i + 1] = ps[i] + a[i];
  }
  auto get = [&](int l, int r) {
    assert(r + 1 <= n && 0 <= l);
    return ps[r + 1] - ps[l];
  };
  int mx = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int lo = -1;
    int hi = i;
    while (lo + 1 < hi) {
      int md = lo + (hi - lo) / 2;
      ll tot = (i - md + 1) * (ll) a[i];
      if (get(md, i) + k >= tot) {
        hi = md;
      }
      else {
        lo = md;
      }
    }
    if (mx < i - lo) {
      mx = i - lo;
      ans = a[i];
    }
  }
  cout << mx << " " << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
