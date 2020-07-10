/* created   : 2020-07-10 16:55:48
 * accepted  : 2020-07-10 17:02:55
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

const int N = 120;
const int M = 1e4 + 7;
int a[N];
int f[M];

void solve() {
  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  // f[i][j] += f[i - 1][j - w];
  f[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = m; j >= a[i]; j--) {
      f[j] += f[j - a[i]];
    }
  }
  cout << f[m] << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
