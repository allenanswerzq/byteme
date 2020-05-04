/* created   : 2020-05-03 16:56:50
 * accepted  : 2020-05-03 20:12:45
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
  set<int> st;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    st.insert(a[i]);
  }
  int m; cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    st.insert(b[i]);
  }
  sort(all(a));
  sort(all(b));
  const int inf = 2e9 + 7;
  ll mx = -inf;
  pair<ll, ll> best;
  st.insert(0);
  st.insert(inf);
  for (auto x : st) {
    ll sa = 0, sb = 0;
    int up = upper_bound(all(a), x) - a.begin();
    sa = (n - up) * 3 + up * 2;
    int it = upper_bound(all(b), x) - b.begin();
    sb = (m - it) * 3 + it * 2;
    trace(x, up, it, sa, sb, mx, best);
    if (mx < sa - sb) {
      mx = sa - sb;
      best = {sa, sb};
    }
    else if (mx == sa - sb && best.x < sa) {
      best = {sa, sb};
    }
  }
  trace(mx, best);
  cout << best.x << ":" << best.y << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
