/* created   : 2022-03-09 20:31:43
 * accepted  : 2022-03-10 09:16:02
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

const int INF = 1e3 + 7;
vector<int> ops;

void solve() {
  // ai = ai + [ai / x]
  int N, K; cin >> N >> K;
  vector<int> B(N);
  for (int i = 0; i < N; i++) {
    int b; cin >> b;
    B[i] = ops[b];
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
  //
  // greedy: the maxinum of ops needs from 1 to 1000 is 12
  K = min(K, 12 * N);
  vector<ll> f(K + 1);
  for (int i = 0; i < N; i++) {
    for (int j = K; j >= B[i]; j--) {
      f[j] = max(f[j], f[j - B[i]] + C[i]);
    }
  }
  cout << f[K] << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  ops.resize(INF, INF);
  ops[1] = 0;
  for (int i = 1; i < INF; i++) {
    for (int j = 1; j <= i; j++) {
      int t = i + i / j;
      if (t < INF && ops[t] > ops[i] + 1) {
        ops[t] = ops[i] + 1;
      }
    }
  }
  // trace(ops);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    // cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
