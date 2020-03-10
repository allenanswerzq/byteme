/* created   : 2020-03-08 15:50:52
 * accepted  : 2020-03-08 16:49:54
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void print(vector<int>& a) {
  int n = a.size();
  cout << n << '\n';
  for (int i = 0; i < n; i++) {
    cout << a[i] + 1 << (i == n - 1 ? '\n' : ' ');
  }
}

void solve() {
  int n; cin >> n;
  int mx = 0;
  vector<pair<int, int>> v(n);
  vector<int> g(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].x;
    v[i].y = i;
    g[i] = v[i].x;
    mx = max(mx, v[i].x);
  }
  sort(all(v));
  reverse(all(v));
  ll sa = 0;
  ll sb = 0;
  vector<int> a;
  vector<int> b;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      a.push_back(v[i].y);
      sa += v[i].x;
    }
    else {
      b.push_back(v[i].y);
      sb += v[i].x;
    }
  }
  while (sa - sb > mx) {
    sb += g[a.back()];
    sa -= g[a.back()];
    b.push_back(a.back());
    a.pop_back();
  }
  print(a);
  print(b);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
