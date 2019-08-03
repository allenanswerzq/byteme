/*
 * created   : 2019-08-02 10:00:23
 * accepted  : 2019-08-02 10:30:00
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
  int n, k;
  cin >> n >> k;
  vector<int> a(2 * n);
  iota(a.begin(), a.end(), 1);
  int p = 0;
  for (int i = 0; i < k; i++) {
    swap(a[p], a[p + 1]);
    p += 2;
  }
  for (int i = 0; i < 2 * n; i++) {
    cout << a[i] << (i == 2 * n - 1 ? "\n" : " ");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
