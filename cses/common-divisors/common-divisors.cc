/* created   : 2020-12-17 22:17:11
 * accepted  : 2020-12-17 22:48:39
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

const int Z = 1e6 + 7;

void solve() {
  int N; cin >> N;
  vector<int> cnt(Z);
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    cnt[x]++;
  }
  for (int i = Z - 1; i > 0; i--) {
    int d = 0;
    for (int j = i; j < Z; j += i) {
      // j, 2j, 3j, ...
      d += cnt[j];
      if (d > 1) {
        cout << i << "\n";
        return;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
