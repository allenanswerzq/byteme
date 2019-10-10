/* created   : 2019-10-07 15:21:13
 * accepted  : 2019-10-07 17:23:43
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

string get(int a) {
  int x = a / 26;
  int y = a % 26;
  assert(0 <= x && x <= 26);
  string ret;
  ret += (char) ('A' + x);
  ret += (char) ('a' + y);
  return ret;
}

void solve() {
  int n, k; cin >> n >> k;
  vector<int> v(n);
  iota(v.begin(), v.end(), 0);
  for (int i = 0; i < n - k + 1; i++) {
    string x; cin >> x;
    if (x == "NO") {
      v[i + k - 1] = v[i];
    }
  }
  trace(v);
  for (int i = 0; i < n; i++) {
    cout << get(v[i]) << (i == n - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
