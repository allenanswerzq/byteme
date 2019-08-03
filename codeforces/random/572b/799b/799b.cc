/*
 * created   : 2019-07-28 23:38:32
 * accepted  : 2019-07-29 00:25:19
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
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  vector<set<pair<ll, int>>> fr(4), bk(4);
  for (int i = 0; i < n; i++) {
    fr[b[i]].insert({a[i], c[i]});
    bk[c[i]].insert({a[i], b[i]});
  }
  trace(fr, bk);
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    if (i > 0) {
      cout << " ";
    }
    if (fr[x].empty() && bk[x].empty()) {
      cout << -1;
      continue;
    }
    ll afr = 1e18;
    ll abk = 1e18;
    if (!fr[x].empty()) {
      afr = min(afr, fr[x].begin()->x);
    }
    if (!bk[x].empty()) {
      abk = min(abk, bk[x].begin()->x);
    }
    if (afr < abk) {
      cout << afr;
      int p = fr[x].begin()->x;
      int y = fr[x].begin()->y;
      auto it = bk[y].find({p, x});
      assert(it != bk[y].end());
      bk[y].erase(it);
      fr[x].erase(fr[x].begin());
    }
    else {
      cout << abk;
      int p = bk[x].begin()->x;
      int y = bk[x].begin()->y;
      auto it = fr[y].find({p, x});
      assert(it != fr[y].end());
      fr[y].erase(it);
      bk[x].erase(bk[x].begin());
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
