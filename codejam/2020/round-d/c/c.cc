/* created   : 2020-08-30 10:23:53
 * accepted  : 2020-08-30 14:33:45
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

// @Solution: LCA + Expected value

void solve() {
  int N; cin >> N;
  array<int, 2> A; cin >> A[0] >> A[1];
  vector<array<int, 20>> parent(N);
  vector<int> depth(N);
  for (int v = 1; v < N; v++) {
    int u; cin >> u; u--;
    depth[v] = depth[u] + 1;
    parent[v][0] = u;
    for (int z = 0; parent[v][z]; z++) {
      int p = parent[v][z];
      parent[v][z + 1] = parent[p][z];
    }
  }
  double ans = 0;
  vector<array<int, 2>> cnt(N);
  for (int i = N - 1; i >= 0; i--) {
    for (int z = 0; z < 2; z++) {
      cnt[i][z]++;
      if (depth[i] < A[z]) continue;
      // NOTE: Go up A[z] step
      int cur = i;
      for (int v = A[z], l = 0; v; v >>= 1, l++) {
        if (v & 1) {
          cur = parent[cur][l];
        }
      }
      cnt[cur][z] += cnt[i][z];
    }
    double va = cnt[i][0] * 1.0 / N;
    double vb = cnt[i][1] * 1.0 / N;
    ans += va + vb - va * vb;
  }
  cout << fixed << setprecision(10) << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
