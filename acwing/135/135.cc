/* created   : 2020-06-04 20:13:18
 * accepted  : 2020-06-05 10:29:12
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define pii pair<int, int>

void solve() {
  int n, m, q, u, v, t;
  cin >> n >> m >> q >> u >> v >> t;
  deque<int> qa;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    qa.push_back(x);
  }
  sort(all(qa));
  reverse(all(qa));
  trace(qa);
  deque<int> qb, qc;
  auto get = [&]() {
    int ret = INT_MIN;
    if (qa.size()) {
      ret = max(ret, qa.front());
    }
    if (qb.size()) {
      ret = max(ret, qb.front());
    }
    if (qc.size()) {
      ret = max(ret, qc.front());
    }
    if (qa.size() && qa.front() == ret) {
      qa.pop_front();
      return ret;
    }
    if (qb.size() && qb.front() == ret) {
      qb.pop_front();
      return ret;
    }
    if (qc.size() && qc.front() == ret) {
      qc.pop_front();
      return ret;
    }
    assert(false);
    return ret;
  };
  int delta = 0;
  for (int i = 1; i <= m; i++) {
    int mx = get() + delta;
    delta += q;
    int lt = mx * 1ll * u / v;
    int rt = mx - lt;
    qb.push_back(lt - delta);
    qc.push_back(rt - delta);
    trace(i, mx, delta, qa, qb, qc);
    if (i % t == 0) {
      cout << mx << " ";
    }
  }
  cout << "\n";
  trace(qa, qb, qc);
  for (int i = 1; i <= n + m; i++) {
    int mx = get();
    if (i % t == 0) {
      cout << mx + delta << " ";
    }
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
