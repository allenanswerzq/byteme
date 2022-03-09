/* created   : 2022-03-09 20:31:43
 * accepted  : 2022-03-09 23:26:35
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

template <bool ONE = false>
struct Discreter {
  unordered_map<int, int> raw_dis_;
  vector<int> sorted_;

  Discreter(const vector<int> &val) {
    sorted_ = val;
    sort(all(sorted_));
    sorted_.erase(unique(all(sorted_)), sorted_.end());
    for (int &x : val) {
      int p = lower_bound(all(sorted_), x) - sorted_.begin() + ONE;
      raw_dis_[x] = p;
    }
  }

  // The maxinum value after discreting
  int max() { return sorted_.size(); }

  // Given a raw value, returns the discreted value.
  int get(int r) { return raw_dis_[r]; }

  // Given a discreted value, returns the raw value.
  int old(int d) { return sorted_[d - ONE]; }
};

const int INF = 1e3 + 7;
vector<int> dist;

void solve() {
  // ai = ai + [ai / x]
  int N, K; cin >> N >> K;
  vector<int> B(N);
  for (int i = 0; i < N; i++) {
    int b; cin >> b;
    B[i] = dist[b];
  }
  vector<int> C(N);
  vector<int> pos;
  for (int i = 0; i < N; i++) {
    cin >> C[i];
    auto it = lower_bound(all(pos), )
  }
  trace(B);
  // knapsack problem
}

void solve_naive() {
  // ai = ai + [ai / x]
  int N, K; cin >> N >> K;
  vector<int> B(N);
  for (int i = 0; i < N; i++) {
    int b; cin >> b;
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
