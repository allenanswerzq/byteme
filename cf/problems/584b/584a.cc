/* created   : 2020-02-04 10:14:48
 * accepted  : 2020-02-04 12:36:07
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

const int mod = 1e9 + 7;

void add(int& a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

void sub(int& a, int b) {
  a -= b;
  if (a < 0) {
    a += mod;
  }
}

int mul(int a, int b) { return (int)((ll)a * b % mod); }

int power(int a, ll b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

void solve() {
  int n; cin >> n;
  int x = power(27, n);
  sub(x, power(7, n));
  cout << x << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
