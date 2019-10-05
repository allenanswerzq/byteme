/*
 * creat   : 2019-07-20 11:03:34
 * accept  : 2019-07-20 13:29:23
 * author  : landcold7
 */
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define sz(x) ((int)(x).size())
#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;

// void solve_segtree() {
//   int n, k, q;
//   cin >> n >> k >> q;
//   const int N = 2e5 + 7;
//   segtree st(N);
//   for (int i = 0; i < n; ++i) {
//     int x, y;
//     cin >> x >> y;
//     st.modify(x, y + 1, 1);
//   }
//   // trace(st.tree);
//   vector<int> pr(N);
//   for (int i = 1; i < N; ++i) {
//     pr[i] = pr[i - 1] + (st.get(i).sum >= k);
//   }
//   // trace(pr);
//   for (int i = 0; i < q; ++i) {
//     int x, y;
//     cin >> x >> y;
//     cout << pr[y] - pr[x - 1] << "\n";
//   }
// }

void solve() {
  int n, k, q;
  cin >> n >> k >> q;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    cin >> b[i];
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  const int N = 2e5 + 7;
  vector<int> pr(N);
  for (int i = 1; i < N; ++i) {
    int x = upper_bound(a.begin(), a.end(), i) - a.begin();
    int y = lower_bound(b.begin(), b.end(), i) - b.begin();
    pr[i] = pr[i - 1] + (x - y >= k);
  }
  for (int i = 0; i < q; ++i) {
    int x, y;
    cin >> x >> y;
    cout << pr[y] - pr[x - 1] << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
