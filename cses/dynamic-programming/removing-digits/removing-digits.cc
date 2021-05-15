/* created   : 2020-11-12 20:04:28
 * accepted  : 2020-11-12 20:09:11
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int N; cin >> N;
  const int INF = 1e9 + 7;
  vector<int> f(N + 1, INF);
  f[0] = 0;
  for (int i = 1; i <= N; i++) {
    for (char c : to_string(i)) {
      int x = c - '0';
      f[i] = min(f[i], f[i - x] + 1);
    }
  }
  cout << f[N] << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
