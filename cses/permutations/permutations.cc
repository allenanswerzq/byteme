/* created   : 2020-10-29 22:29:23
 * accepted  : 2020-10-29 22:40:37
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long


// 1 2 3
// 2 4 1 3
// 1 3 5 2 4
// 1 3 5 2 4 6
// 1 3 5 7 2 4 6

void solve() {
  int N; cin >> N;
  if (N == 1) {
    cout << "1\n";
    return;
  }
  else if (N <= 3) {
    cout << "NO SOLUTION\n";
    return;
  }
  else if (N == 4) {
    cout << "2 4 1 3\n";
    return;
  }
  for (int i = 1; i <= N; i += 2) {
    cout << i << " ";
  }
  for (int i = 2; i <= N; i += 2) {
    cout << i << " ";
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
