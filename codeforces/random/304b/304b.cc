/* created   : 2019-08-18 14:02:01
 * accepted  : 2019-08-18 14:51:23
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

bool is_leap(int t) {
  return (t % 4 == 0 && t % 100) || (t % 400 == 0);
}

int get(vector<int>& x) {
  vector<int> day = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int ans = 0;
  for (int i = 1; i < x[0]; i++) {
    ans += (is_leap(i) ? 366 : 365);
  }
  for (int i = 1; i < x[1]; i++) {
    ans += (is_leap(x[0]) && i == 2 ? 29 : day[i]);
  }
  ans += x[2];
  return ans;
}

void solve() {
  string a, b;
  cin >> a >> b;
  a += ':';
  b += ':';
  istringstream isa(a), isb(b);
  char c;
  vector<int> x(3);
  for (int i = 0; i < 3; i++) {
    isa >> x[i] >> c;
  }
  vector<int> y(3);
  for (int i = 0; i < 3; i++) {
    isb >> y[i] >> c;
  }
  cout << abs(get(x) - get(y)) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
