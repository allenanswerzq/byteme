/* created   : 2022-03-22 11:12:18
 * accepted  : 2022-03-22 21:06:34
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

const int mod = 998244353;

void solve() {
  int N, M, K, Q; cin >> N >> M >> K >> Q;
  vector<ar> A(Q);
  for (int i = 0; i < Q; i++) {
    cin >> A[i][0] >> A[i][1];
  }
  set<int> col;
  set<int> row;
  int cnt = 0;
  int ans = 1;
  for (int i = Q - 1; i >= 0; i--) {
    int r = A[i][0], c = A[i][1];
    if (col.count(c) && row.count(r)) {
      // both row and column are recolored
    }
    else if (row.size() == N || col.size() == M) {
      // all rows/colomns are recolored.
    }
    else {
      cnt++;
      ans = ((ll)ans * K) % mod;
    }
    col.insert(c);
    row.insert(r);
  }
  trace(cnt);
  cout << ans << "\n";
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
