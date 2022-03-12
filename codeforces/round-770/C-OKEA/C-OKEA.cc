/* created   : 2022-03-12 16:41:09
 * accepted  : 2022-03-12 17:07:23
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  // 1, 2, 3, ... n * k
  // avg = sum / (r - l + 1)
  // n * k = 2 * 3
  // 1, 3, 5,
  // 2, 4, 6,
  //
  // 1 3 5
  // 2 4 6
  // 7 9 11
  // 8 10 12
  //
  int N, K; cin >> N >> K;
  int t = N * K;
  int even = t / 2;
  int odd = t - even;
  if (even % K || odd % K) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  for (int i = 1, j = 1; i <= t; i += 2, j++) {
    cout << i;
    if (j % K == 0) {
      cout << "\n";
    }
    else {
      cout << " ";
    }
  }
  for (int i = 2, j = 1; i <= t; i += 2, j++) {
    cout << i;
    if (j % K == 0) {
      cout << "\n";
    }
    else {
      cout << " ";
    }
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
