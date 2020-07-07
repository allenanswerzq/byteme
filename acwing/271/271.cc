/* created   : 2020-07-07 14:18:22
 * accepted  : 2020-07-07 14:28:53
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

const int N = 32;
ll f[N][N][N][N][N];
int n;

void solve() {
  vector<int> cnt(5);
  for (int i = 0; i < n; i++) {
    cin >> cnt[i];
  }
  memset(f, 0, sizeof(f));
  f[0][0][0][0][0] = 1;
  for (int a = 0; a <= cnt[0]; a++) {
    for (int b = 0; b <= min(a, cnt[1]); b++) {
      for (int c = 0; c <= min(b, cnt[2]); c++) {
        for (int d = 0; d <= min(c, cnt[3]); d++) {
          for (int e = 0; e <= min(d, cnt[4]); e++) {
            ll& x = f[a][b][c][d][e];
            if (a > 0 && a - 1 >= b) x += f[a - 1][b][c][d][e];
            if (b > 0 && b - 1 >= c) x += f[a][b - 1][c][d][e];
            if (c > 0 && c - 1 >= d) x += f[a][b][c - 1][d][e];
            if (d > 0 && d - 1 >= e) x += f[a][b][c][d - 1][e];
            if (e > 0) x += f[a][b][c][d][e - 1];
          }
        }
      }
    }
  }
  cout << f[cnt[0]][cnt[1]][cnt[2]][cnt[3]][cnt[4]] << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  while (cin >> n && n) {
    solve();
  }
  return 0;
}
