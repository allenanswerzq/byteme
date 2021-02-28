/* created   : 2021-02-21 16:39:26
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

ll f[20][10][2][2];

ll go(const string& num, int i, int x, bool leading_zero, bool tight) {
  // NOTE: x is the digit should not be appeared at `i`th position
  // trace(i, x, leading_zero, tight);
  if (i == num.size()) {
    return 1;
  }
  if (~x && f[i][x][leading_zero][tight] != -1) {
    return f[i][x][leading_zero][tight];
  }
  int lo = 0;
  int hi = tight ? (num[i] - '0') : 9;
  ll ans = 0;
  for (int d = lo; d <= hi; d++) {
    if (!leading_zero && d == x) {
      continue;
    }
    ans += go(num, i + 1, d, leading_zero & d == 0, tight & d == hi);
  }
  if (~x) {
    f[i][x][leading_zero][tight] = ans;
  }
  return ans;
}

ll compute(ll x) {
  // 12345
  memset(f, -1, sizeof(f));
  string s = to_string(x);
  return go(s, 0, -1, 1, 1);
}

void solve() {
  ll A, B; cin >> A >> B;
  cout << compute(B) - compute(A - 1) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
