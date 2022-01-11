/* created   : 2022-01-10 22:56:26
 * accepted  : 2022-01-10 23:38:23
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int N; cin >> N;
  vector<set<int>> A(N);
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    while (x > 0) {
      if (1 <= x && x <= N) {
        A[i].insert(x);
      }
      x /= 2;
    }
  }
  trace(A);
  for (int i = N; i >= 1; i--) {
    bool ok = false;
    for (int k = 0; k < N; k++) {
      if (A[k].count(i)) {
        ok = true;
        A[k].clear();
        break;
      }
    }
    if (!ok) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    // cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
