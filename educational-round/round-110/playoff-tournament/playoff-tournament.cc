/* created   : 2021-08-29 07:57:06
 * accepted  : 2021-08-29 10:37:42
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
    int u = M - p;
    int ans = 0;
    if (ch == '?') {
      ans = f[2 * u] + f[2 * u + 1];
    }
    else if (ch == '0') {
      ans = f[2 * u + 1];
    }
    else {
      ans = f[2 * u];
    }
    trace("start", p, u, ans);
    for (; u != 1; u /= 2) {
      int parent = u / 2;
      int cur = 0;
      trace(i, parent, u, ans, M - parent);
      if (S[M - parent] == '?') {
        // If u is a left child
        cur = ans + ((u & 1) ? f[2 * parent] : f[2 * parent + 1]);
      }
      else if (S[M - parent] == '0') {
        // >
        cur = (u & 1) ? ans : f[2 * parent + 1];
      }
      else {
        cur = (u & 1) ? f[2 * parent] : ans;
      }
      ans = cur;
      trace(i, u, ans);
    }
    cout << ans << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
