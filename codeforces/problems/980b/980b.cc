/* created   : 2020-09-07 23:00:49
 * accepted  : 2020-09-07 23:32:33
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int N, K; cin >> N >> K;
  vector<string> a(4, string(N, '.'));
  bool odd = false;
  if (K % 2) {
    K--;
    odd = true;
  }
  cout << "YES\n";
  int r = 1;
  while (K) {
    for (int i = 1; i < N / 2 && K; i++) {
      a[r][i] = '#';
      a[r][N - 1 - i] = '#';
      K -= 2;
    }
    if (++r == 3) {
      break;
    }
  }
  if (K == 2) {
    a[1][N / 2] = '#';
    a[2][N / 2] = '#';
  }
  else if (odd) {
    a[1][N / 2] = '#';
  }
  for (auto& s : a) {
    cout << s << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
