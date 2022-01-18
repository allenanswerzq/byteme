/* created   : 2022-01-17 23:48:04
 * accepted  : 2022-01-19 06:29:04
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<ll, 2>;

void amin(ll& a, ll b) { a = min(a, b); }

void solve() {
  int N, M, K; cin >> N >> M >> K;
  vector<ll> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  A.push_back(M);
  vector<ll> B(N);
  for (int i = 0; i < N; i++) {
    cin >> B[i];
  }
  const int INF = 1e9 + 7;
  B.push_back(INF);
  // f(i, k) we are at the ith position, removed k signs before
  // f(j, k + j - i - 1) = f(i, k) + (a[j] - a[i]) * b[i] (for all j > i)
  vector<vector<ll>> f(N + 1, vector<ll>(K + 1, INF));
  f[0][0] = 0;
  for (int i = 1; i <= N; i++) {
    f[i][0] = f[i - 1][0] + (A[i] - A[i - 1]) * B[i - 1];
  }
  for (int i = 0; i <= N; i++) {
    // NOTE: doesn't matter the loop order for j and k
    for (int j = i + 1; j <= N; j++) {
      for (int k = 0; k <= K; k++) {
        if (k + j - i - 1 <= K) {
          amin(f[j][k + j - i - 1], f[i][k] + (A[j] - A[i]) * B[i]);
        }
      }
    }
  }
  trace(f);
  ll ans = INF;
  for (int k = 0; k <= K; k++) {
    ans = min(ans, f[N][k]);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
