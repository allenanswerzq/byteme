/* created   : 2020-02-12 21:36:28
 * accepted  : 2020-02-12 22:20:14
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

void solve() {
  string s; cin >> s;
  int n = s.size();
  vector<int> a(n);
  for (int i = 1; i < n; i++) {
    if (s[i] == 'b') {
      a[i] = 0;
    }
    else {
      a[i - 1] ^= 1;
      a[i] = 1;
    }
  }
  for (int i = 1; i < n; i++) {
    if (a[i] == 1) {
      reverse(s.begin(), s.begin() + i + 1);
    }
  }
  trace(s);
  for (int i = 0; i < n; i++) {
    cout << a[i] << (i == n - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
