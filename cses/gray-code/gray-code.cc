/* created   : 2021-02-01 22:45:35
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

void solve() {
  // 00 0
  // 01 1
  // 11 3
  // 10 2

  // 000 0
  // 001 1
  // 011 3
  // 010 2

  // 110 6
  // 111 7
  // 101 5
  // 100 4
  int N; cin >> N;
  vector<int> ans = {0, 1};
  for (int i = 2; i <= N; i++) {
    int m = 1 << (i - 1);
    for (int j = m - 1; j >= 0; j--) {
      ans.push_back(ans[j] | m);
    }
  }
  for (auto x : ans) {
    for (int i = N - 1; i >= 0; i--) {
      cout << ((x >> i) & 1);
    }
    cout << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
