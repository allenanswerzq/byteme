/*
 * Creat   : Sat Jul 13 21:04:44 CST 2019
 * Accept  : Sat Jul 13 21:15:00 CST 2019
 * Author  : landcold7
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
  int n;
  cin >> n;
  int k;
  cin >> k;
  vector<int> a(k);
  for (int i = 0; i < k; ++i) {
    cin >> a[i];
  }
  cin >> k;
  vector<int> b(k);
  for (int i = 0; i < k; ++i) {
    cin >> b[i];
  }
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  trace(a, b);
  int cnt = 0;
  while (sz(a) && sz(b) && cnt <= 1000000) {
    cnt++;
    int x = a.back();
    a.pop_back();
    int y = b.back();
    b.pop_back();
    // trace(x, y, a, b, cnt);
    if (x > y) {
      a.insert(a.begin(), y);
      a.insert(a.begin(), x);
    }
    else {
      b.insert(b.begin(), x);
      b.insert(b.begin(), y);
    }
    // trace(x, y, a, b);
  }
  int win = 0;
  if (sz(a) == 0) {
    win = 2;
  }
  else if (sz(b) == 0) {
    win = 1;
  }
  else {
    win = -1;
  }
  if (win == -1) {
    cout << -1 << "\n";
  }
  else {
    cout << cnt << " " << win << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
