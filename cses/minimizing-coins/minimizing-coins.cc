/* created   : 2020-11-12 16:32:46
 * accepted  : 2020-11-12 16:36:11
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int N, X; cin >> N >> X;
  vector<int> C(N);
  for (int& c : C) {
    cin >> c;
  }
  const int INF = 1e9 + 7;
  vector<int> f(X + 1, INF);
  f[0] = 0;
  for (int i = 1; i <= X; i++) {
    for (int c : C) {
      if (i - c >= 0) {
        f[i] = min(f[i], f[i - c] + 1);
      }
    }
  }
  cout << (f[X] == INF ? -1 : f[X]) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
