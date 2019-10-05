/*
 * creat   : 2019-07-20 19:13:25
 * accept  : 2019-07-20 19:27:04
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

void solve() {
  int n, m;
  cin >> n >> m;
  int k;
  cin >> k;
  set<int> a, b;
  for (int i = 0; i < k; ++i) {
    int x;
    cin >> x;
    a.insert(x);
  }
  cin >> k;
  for (int i = 0; i < k; ++i) {
    int x;
    cin >> x;
    b.insert(x);
  }
  for (int i = 0; i < (int) 1e5; ++i) {
    // trace(i % n, i % m);
    bool x = a.count(i % n);
    bool y = b.count(i % m);
    if (x ^ y) {
      a.insert(i % n);
      b.insert(i % m);
    }
  }
  trace(a, b);
  cout << (sz(a) == n && sz(b) == m ? "Yes" : "No") << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
