/* created   : 2022-03-24 08:49:34
 * accepted  : 2022-03-24 09:02:12
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int N; cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  sort(all(A));
  int cnt = 0;
  for (int i = 0; i < N; ) {
    int j = i;
    while (j < N && A[j] == A[i]) {
      j++;
    }
    cnt++;
    i = j;
  }
  for (int k = 1; k <= N; k++) {
    int c = 0;
    if (k <= cnt) {
      c = cnt;
    }
    else {
      c = k;
    }
    cout << c << (k == N ? '\n' : ' ');
  }
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
