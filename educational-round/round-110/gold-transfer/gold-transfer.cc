/* created   : 2021-08-30 07:25:11
 * accepted  : 2021-09-04 18:26:09
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int Q; cin >> Q;
  vector<int> A(Q + 1);
  vector<int> C(Q + 1);
  cin >> A[0] >> C[0];
  vector<vector<int>> pre(Q + 1, vector<int>(20, -1));
  for (int i = 1; i <= Q; i++) {
    int op; cin >> op;
    if (op == 1) {
      int p; cin >> p >> A[i] >> C[i];
      // i-->p
      pre[i][0] = p;
      for (int k = 1; k < 20; k++) {
        int u = pre[i][k - 1];
        pre[i][k] = (u != -1 ? pre[u][k - 1] : -1);
      }
    }
    else {
      int v, w; cin >> v >> w;
      ll ans = 0;
      ll buy = 0;
      while (w > 0 && A[v] > 0) {
        int u = v;
        // Find the highest vertex that A[u] > 0
        for (int k = 19; k >= 0; k--) {
          if (pre[u][k] != -1 && A[pre[u][k]] > 0) {
            u = pre[u][k];
          }
        }
        int mi = min(w, A[u]);
        w -= mi;
        A[u] -= mi;
        buy += mi;
        ans += mi * 1ll * C[u];
      }
      cout << buy << " " << ans << endl;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
