/* created   : 2020-11-13 09:23:15
 * accepted  : 2020-11-13 09:41:27
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int N, X; cin >> N >> X;
  vector<int> H(N);
  for (int& h : H) {
    cin >> h;
  }
  vector<int> S(N);
  for (int& s : S) {
    cin >> s;
  }
  // f[i][x] = max(f[i - 1][x], f[i - 1][x - hi] + si);
  vector<int> f(X + 1);
  for (int i = 0; i < N; i++) {
    vector<int> p(X + 1);
    for (int j = 0; j <= X; j++) {
      p[j] = f[j];
      if (j >= H[i]) {
        p[j] = max(p[j], f[j - H[i]] + S[i]);
      }
    }
    swap(f, p);
  }
  cout << f[X] << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
