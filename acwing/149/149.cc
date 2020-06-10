/* created   : 2020-06-09 22:35:12
 * accepted  : 2020-06-10 10:25:57
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int n, k; cin >> n >> k;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  const int INF = 1e9 + 7;
  vector<int> d(n + 2);
  d[1] = d[n + 1] = INF;
  for (int i = 2; i <= n; i++) {
    d[i] = a[i] - a[i - 1];
  }
  vector<int> pre(n + 2);
  vector<int> nxt(n + 2);
  set<pair<ll, int>> st;
  for (int i = 1; i <= n + 1; i++) {
    pre[i] = max(i - 1, 0);
    nxt[i] = min(i + 1, n + 1);
    st.insert({d[i], i});
  }
  auto delete_node = [&](int p) {
    nxt[pre[p]] = nxt[p];
    pre[nxt[p]] = pre[p];
  };
  ll ans = 0;
  for (int i = 0; i < k; i++) {
    auto it = st.begin();
    ans += it->x;
    int p = it->y;
    int l = pre[p], r = nxt[p];
    // trace(p, n, l, r, d, pre, nxt);
    st.erase(it);
    st.erase({d[l], l});
    st.erase({d[r], r});
    delete_node(l);
    delete_node(r);
    d[p] = d[l] + d[r] - d[p];
    st.insert({d[p], p});
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
