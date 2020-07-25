/* created   : 2020-04-27 22:12:05
 * accepted  : 2020-04-27 23:29:34
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  vector<ll> ps(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ps[i + 1] = ps[i] + a[i];
  }
  auto get = [&](int l, int r) {
    assert(0 <= l && r + 1 <= n);
    return ps[r + 1] - ps[l];
  };
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    b[i]--;
  }
  trace(a, b);
  unordered_map<int, int> rt, lt;
  ll mx = 0;
  vector<ll> ans;
  for (int i = n - 1; i >= 0; i--) {
    ans.push_back(mx);
    int x = b[i];
    int hi = b[i];
    int lo = b[i];
    auto it = rt.find(x + 1);
    if (it != rt.end()) {
      hi = it->y;
      rt.erase(it);
    }
    it = lt.find(x - 1);
    if (it != lt.end()) {
      lo = it->y;
      lt.erase(it);
    }
    rt[lo] = hi;
    lt[hi] = lo;
    mx = max(mx, get(lo, hi));
  }
  for (int i = n - 1; i >= 0; i--) {
    cout << ans[i] << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
