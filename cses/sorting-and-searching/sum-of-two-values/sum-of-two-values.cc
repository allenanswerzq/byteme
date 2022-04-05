/* created   : 2020-11-05 19:07:17
 * accepted  : 2020-11-05 19:19:36
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ar array<int, 2>

void solve() {
  int N, X; cin >> N >> X;
  map<int, int> mp;
  for (int i = 0; i < N; i++) {
    int t; cin >> t;
    if (mp.count(X - t)) {
      cout << mp[X - t] + 1 << " " << i + 1 << "\n";
      return;
    }
    mp[t] = i;
  }
  cout << "IMPOSSIBLE\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
