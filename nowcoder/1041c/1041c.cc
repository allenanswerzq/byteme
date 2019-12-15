/* created   : 2019-12-15 10:29:53
 * accepted  : 2019-12-15 16:36:54
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

template <class T>
vector<int> discrete(vector<T>& v, vector<T>* t, int* m, bool one = true) {
  int off = one ? 1 : 0;
  sort(t->begin() + off, t->end());
  t->erase(unique(t->begin() + off, t->end()), t->end());
  int vs = v.size();
  vector<int> idx(vs);
  for (int i = off; i < vs; i++) {
    idx[i] = lower_bound(t->begin(), t->end(), v[i]) - t->begin();
  }
  *m = t->size() - off;
  return idx;
}

void solve() {
  int n; cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  // discrete the input.
  int m;
  vector<int> dis = a;
  vector<int> idx = discrete<int>(a, &dis, &m);
  // trace(m, dis, idx);
  // f(i, j) = min(f(i - 1, k)) + |Ai - j|
  const int INF = 1e9 + 7;
  vector<vector<int>> f(n + 1, vector<int>(m + 1, INF));
  f[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    int mi = f[i - 1][0];
    for (int j = 1; j <= m; j++) {
      mi = min(mi, f[i - 1][j]);
      f[i][j] = mi + abs(a[i] - dis[j]);
    }
  }
  int ans = INF;
  for (int i = 1; i <= m; i++) {
    ans = min(ans, f[n][i]);
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
