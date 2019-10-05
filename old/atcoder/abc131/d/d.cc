/* Name        : d
 * Creat       : Fri Jul 12 18:11:56 CST 2019
 * Accept      : Fri Jul 12 18:20:50 CST 2019
 * Author      : landcold7
 * Motivation  : Action speaks louder more than words
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
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].x >> a[i].y;
  }
  typedef pair<int, int> pii;
  sort(a.begin(), a.end(), [](const pii& c, const pii& d){
    if (c.y == d.y) {
      return c.x < d.x;
    }
    else {
      return c.y < d.y;
    }
  });
  trace(a);
  int t = 0;
  for (int i = 0; i < n; ++i) {
    t += a[i].x;
    if (t > a[i].y) {
      cout << "No" << "\n";
      return;
    }
  }
  cout << "Yes" << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
