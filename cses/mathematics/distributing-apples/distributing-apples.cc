/* created   : 2020-12-19 15:43:55
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

int inv(int a, int m) {
  a %= m;
  assert(a);
  return a == 1 ? 1 : int(m - ll(inv(m, a)) * ll(m) / a);
}

const int mod = 1e9 + 7;

int mul(int a, int b) { return (ll) a * b % mod; }

void solve() {
  const int Z = 2e6;
  vector<int> f1(Z + 1);
  vector<int> f2(Z + 1);
  vector<int> iv(Z + 1);
  for (int i = 1; i <= Z; i++) {
    iv[i] = inv(i, mod);
  }
  f1[0] = f2[0] = 1;
  for (int i = 1; i <= Z; i++) {
    f1[i] = mul(f1[i - 1], i);
    f2[i] = mul(f2[i - 1], iv[i]);
  }
  int N, M; cin >> N >> M;
  int ans = f1[N + M - 1];
  ans = mul(ans, f2[M]);
  ans = mul(ans, f2[N - 1]);
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
