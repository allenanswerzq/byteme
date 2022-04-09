/* created   : 2020-11-13 14:23:51
 * accepted  : 2020-11-13 15:43:02
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

const int Z = 5e3;
ll f[Z][Z];

void solve() {
  // f[l][h] = s1 - s2
  // [l............h]
  // f[l][h] = max(-(f[l+1][h] - x[l]), x[h] - f[l][h-1]);
  // f[l][h] = max(x[l] + s2 - s1, x[h] + s2 - s1)
  int N; cin >> N;
  vector<ll> A(N);
  ll s = 0;
  for (ll& a : A) {
    cin >> a;
    s += a;
  }
  for (int i = N - 1; i >= 0; i--) {
    for (int len = 1; i + len <= N; len++) {
      int j = i + len - 1;
      if (i == j) {
        f[i][j] = A[i];
      }
      else {
        f[i][j] = max(A[i] - f[i + 1][j], A[j] - f[i][j - 1]);
      }
    }
  }
  ll d = f[0][N - 1];
  trace(d, s);
  // x - y = d;
  // x + y = s;
  cout << (d + s) / 2 << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
