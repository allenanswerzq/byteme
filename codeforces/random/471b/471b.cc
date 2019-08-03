/*
 * created   : 2019-07-24 15:34:25
 * accepted  : 2019-07-24 19:09:05
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
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].x;
    a[i].y = i;
  }
  sort(a.begin(), a.end());
  int cnt = 0;
  vector<int> p;
  for (int i = 0; i < n - 1; ++i) {
    if (a[i].x == a[i + 1].x) {
      cnt++;
      p.push_back(i);
    }
  }
  if (cnt < 2) {
    cout << "NO" << "\n";
    return;
  }
  cout << "YES" << "\n";
  for (int i = 0; i < n; ++i) {
    cout << a[i].y + 1 << (i == n - 1 ? "\n" : " ");
  }
  swap(a[p[0]], a[p[0] + 1]);
  for (int i = 0; i < n; ++i) {
    cout << a[i].y + 1 << (i == n - 1 ? "\n" : " ");
  }
  swap(a[p[1]], a[p[1] + 1]);
  for (int i = 0; i < n; ++i) {
    cout << a[i].y + 1 << (i == n - 1 ? "\n" : " ");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
