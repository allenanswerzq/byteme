/*
 * created   : 2019-07-21 08:46:45
 * accepted  : 2019-07-21 09:57:56
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

void add(int p, int x) {
  cout << 1 << " " << p + 1 << " " << x << "\n";
}

void mod(int p, int x) {
  cout << 2 << " " << p + 1 << " " << x << "\n";
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  cout << n + 1 << "\n";
  ll sum = 0;
  for (int i = n - 1; i >= 0; --i) {
    int x = (i - (a[i] + sum) % n + n);
    sum += x;
    a[i] = (a[i] + sum) % n;
    add(i, x);
  }
  mod(n - 1, n);
  trace(a);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
