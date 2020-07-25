/* created   : 2020-03-16 17:24:05
 * accepted  : 2020-03-16 18:12:36
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
#define debugstream ostream
#endif
typedef long long ll;
typedef pair<int, int> pii;

int mod;

int add(int& a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
  return a;
}

int sub(int& a, int b) {
  a -= b;
  if (a < 0) {
    a += mod;
  }
  return a;
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
  int n; cin >> n >> mod;
  int x = power(3, n);
  cout << sub(x, 1) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
