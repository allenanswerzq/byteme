/* created   : 2020-11-12 16:40:26
 * accepted  : 2020-11-12 16:47:04
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

const int mod = 1e9 + 7;

void add(int& a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

void solve() {
  int N, X; cin >> N >> X;
  vector<int> C(N);
  for (int& c : C) {
    cin >> c;
  }
  vector<int> f(X + 1);
  f[0] = 1;
  for (int i = 1; i <= X; i++) {
    //  [0 1 2 3 4 5 6 7 8 9]
    // 2 2 5
    for (int c : C) {
      if (i - c >= 0) {
        add(f[i], f[i - c]);
      }
    }
  }
  cout << f[X] << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
