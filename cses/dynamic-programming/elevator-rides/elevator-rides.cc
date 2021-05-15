/* created   : 2021-02-20 22:07:31
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

void solve() {
  int N, X; cin >> N >> X;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  vector<pair<int, ll>> f(1 << N);
  f[0] = {1, 0};
  for (int s = 1; s < (1 << N); ++s) {
    f[s] = {N + 1, 0};
    for (int i = 0; i < N; ++i) {
      if (s >> i & 1) {
        auto pre = f[s ^ (1 << i)];
        if (pre.second + A[i] <= X) {
          pre.second += A[i];
        }
        else {
          pre.first++;
          pre.second = A[i];
        }
        f[s] = min(f[s], pre);
      }
    }
  }
  cout << f[(1 << N) - 1].first << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
