/*
 * created   : 2019-07-26 23:28:55
 * accepted  : 2019-07-27 07:46:08
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define sz(x) ((int)(x).size())
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n, q;
  cin >> n >> q;
  vector<ll> pr(n + 1);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    pr[i + 1] = pr[i] + x;
  }
  vector<ll> query(q + 1);
  for (int i = 0; i < q; ++i) {
    ll x;
    cin >> x;
    if (query[i] >= pr[n]) {
      query[i] = 0;
    }
    query[i + 1] = query[i] + x;
  }
  if (query[q] >= pr[n]) {
    query[q] = 0;
  }
  trace(pr, query);
  for (int i = 1; i <= q; ++i) {
    int x = upper_bound(pr.begin(), pr.end(), query[i]) - pr.begin();
    cout << n - x + 1 << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
