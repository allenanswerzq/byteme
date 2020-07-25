/* created   : 2020-05-16 11:33:45
 * accepted  : 2020-05-16 16:16:48
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const int mod = 1e9 + 7;

int mul(int a, int b) {
  return (ll) a * b % mod;
}

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
  int n, q; cin >> n >> q;
  string s; cin >> s;
  vector<int> ps(n + 1);
  for (int i = 0; i < n; i++) {
    ps[i + 1] = ps[i] + (s[i] == '1');
  }
  for (int i = 0; i < q; i++) {
    int l, r; cin >> l >> r;
    int one = ps[r] - ps[l - 1];
    int zeo = r - l + 1 - one;
    trace(i, one, zeo);
    cout << (power(2, one) - 1) * 1ll * power(2, zeo) % mod << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
