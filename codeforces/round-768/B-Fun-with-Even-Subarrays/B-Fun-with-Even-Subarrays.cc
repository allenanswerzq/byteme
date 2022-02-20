/* created   : 2022-02-19 16:37:56
 * accepted  : 2022-02-20 10:30:01
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
  // greedy: the final array must equal to A[N - 1]
  int a = A[N - 1];
  int i = N - 1;
  int ans = 0;
  trace(A);
  while (i >= 0) {
    trace(i);
    while (i >= 0 && A[i] == a) {
      i--;
    }
    trace(i, ans);
    if (i == -1) {
      break;
    }
    ans++;
    // i [a, a, a, a] N
    int len = N - i - 1;
    trace(i, a, ans, len);
    if (len >= i + 1) {
      break;
    }
    else {
      i = i - len;
    }
  }
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
