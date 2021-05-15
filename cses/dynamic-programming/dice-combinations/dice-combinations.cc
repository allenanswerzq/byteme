/* created   : 2020-11-12 15:18:15
 * accepted  : 2020-11-12 15:22:40
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

const int mod = 1e9 + 7;

void add(int& a, int b) { a = (a + b) % mod; }

void solve() {
  int N; cin >> N;
  // f[i] = sum(f[i - x])
  vector<int> f(N + 1);
  f[0] = 1;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= 6; j++) {
      if (i - j >= 0) {
        add(f[i], f[i - j]);
      }
    }
  }
  cout << f[N] << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
