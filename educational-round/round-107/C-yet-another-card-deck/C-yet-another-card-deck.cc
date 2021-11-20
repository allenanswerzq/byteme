/* created   : 2021-11-20 14:23:05
 * accepted  : 2021-11-20 15:42:58
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  // 1 2 3 4
  int N, Q; cin >> N >> Q;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < Q; i++) {
    int c; cin >> c;
    int p = find(all(A), c) - A.begin();
    if (i > 0) {
      cout << " ";
    }
    cout << p + 1;
    rotate(A.begin(), A.begin() + p, A.begin() + p + 1);
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
