/* created   : 2021-02-11 08:36:02
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

void solve() {
  int N, M; cin >> N >> M;
  vector<int> index(N);
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    x--;
    A[i] = x;
    index[x] = i;
  }
  int ans = 1;
  for (int i = 1; i < N; i++) {
    ans += index[i] < index[i - 1];
  }
  set<array<int, 2>> cand;
  auto collect = [&](int k) {
    if (A[k] > 0) cand.insert({A[k] - 1, A[k]});
    if (A[k] < N - 1) cand.insert({A[k], A[k] + 1});
  };
  for (int i = 0; i < M; i++) {
    int a, b; cin >> a >> b;
    a--, b--;
    collect(a);
    collect(b);
    // Remove the old contribution to the answer first
    for (auto& x : cand) {
      ans -= index[x[1]] < index[x[0]];
    }
    swap(index[A[a]], index[A[b]]);
    swap(A[a], A[b]);
    // Add the new contribution
    for (auto& x : cand) {
      ans += index[x[1]] < index[x[0]];
    }
    cand.clear();
    cout << ans << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
