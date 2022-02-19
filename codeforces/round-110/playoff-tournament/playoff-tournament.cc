/* created   : 2021-08-29 07:57:06
 * accepted  : 2021-08-29 20:01:30
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int K; cin >> K;
  string S; cin >> S;
  int N = (1 << (K + 1));
  int M = (1 << K) - 1;
  vector<int> f(N);
  for (int i = (1 << K); i < N; i++) {
    f[i] = 1;
  }
  trace(f);
  for (int u = (1 << K) - 1; u >= 1; u--) {
    int i = M - u;
    trace(u, i);
    if (S[i] == '?') {
      f[u] = f[2 * u] + f[2 * u + 1];
    }
    else if (S[i] == '0') {
      // NOTE: left child
      f[u] = f[2 * u + 1];
    }
    else {
      f[u] = f[2 * u];
    }
  }
  trace(f);
  int Q; cin >> Q;
  for (int i = 0; i < Q; i++) {
    int p; char ch; cin >> p >> ch;
    p--;
    S[p] = ch;
    int u = M - p;
    trace(i, p, ch, u);
    while (u > 0) {
      if (S[M - u] == '?') {
        f[u] = f[2 * u + 1] + f[2 * u];
      }
      else if (S[M - u] == '0') {
        // >
        f[u] = f[2 * u + 1];
      }
      else {
        f[u] = f[2 * u];
      }
      u = u / 2;
    }
    cout << f[1] << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
