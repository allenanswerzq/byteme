/* created   : 2020-11-26 22:04:38
 * accepted  : 2020-11-26 22:05:54
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

void solve() {
  int N, Q; cin >> N >> Q;
  vector<ll> ps(N + 1);
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    ps[i + 1] = ps[i] + x;
  }
  for (int i = 0; i < Q; i++) {
    int a, b; cin >> a >> b;
    cout << ps[b] - ps[a - 1] << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
