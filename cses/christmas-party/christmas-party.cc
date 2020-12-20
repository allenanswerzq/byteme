/* created   : 2020-12-19 22:14:13
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

const int mod = 1e9 + 7;

int mul(int a, int b) { return (ll) a * b % mod; }

int add(int a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
  return a;
}

void solve() {
  int N; cin >> N;
  vector<int> f(N + 1);
  f[2] = 1;
  for (int i = 3; i <= N; i++) {
    f[i] = mul(i - 1, add(f[i - 1], f[i - 2]));
  }
  cout << f[N] << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
