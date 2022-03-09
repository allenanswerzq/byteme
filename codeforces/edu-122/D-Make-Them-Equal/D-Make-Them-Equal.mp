/* created   : 2022-03-09 20:31:43
 * accepted  : 2022-03-09 21:37:45
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

const int INF = 1e3 + 7;
vector<int> dist;

void solve() {
  // ai = ai + [ai / x]
  // 1+1/1 = 2, 2+(2, 1) = (4, 3), 4+(4, 2, 1) = (8, 6, 5)
  int N, K; cin >> N >> K;
  vector<int> B(N);
  vector<int> D(N);
  for (int i = 0; i < N; i++) {
    int b; cin >> b;
    D[i] = b;
    B[i] = dist[b];
  }
  vector<int> C(N);
  for (int i = 0; i < N; i++) {
    cin >> C[i];
  }
  trace(B);
  // knapsack problem
  // f[i][j] = max(f[i-1][j], f[i-1][j-k1] + c1)
  // k1, k2, k3, k4
  // c1, c2, c3, c4
  ll ans = 0;
  for (int i = 0; i < (1 << N); i++) {
    ll cur = 0;
    ll cap = 0;
    vector<ar> tmp;
    for (int j = 0; j < N; j++) {
      if (i >> j & 1) {
        cur += C[j];
        cap += B[j];
        tmp.push_back({D[j], B[j]});
      }
    }
    if (cur == 899) {
      trace(cap, K);
      trace(tmp);
    }
    if (cap <= K) {
      ans = max(ans, cur);
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  dist.resize(INF, INF);
  dist[1] = 0;
  for (int i = 1; i < INF; i++) {
    for (int j = 1; j <= i; j++) {
      int t = i + i / j;
      if (t < INF && dist[t] > dist[i] + 1) {
        dist[t] = dist[i] + 1;
      }
    }
  }
  trace(make_tuple(dist, 10));
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    // cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
