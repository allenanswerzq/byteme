/* created   : 2020-09-04 07:45:50
 * accepted  : 2020-09-04 22:29:49
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

void amin(int& a, int b) { a = min(a, b); }

const int NX = 20;
int f[NX][2];
char a[NX][120];

void solve() {
  int N, M; cin >> N >> M;
  for (int i = N; i >= 1; i--) {
    scanf("%s\n", a[i]);
  }
  memset(f, 0x7f, sizeof(f));
  f[1][0] = 0;
  f[1][1] = M + 1;
  for (int i = 2; i <= N; i++) {
    int lo = M + 1;
    int hi = 0;
    for (int j = 1; j <= M; j++) {
      trace(i, a[i - 1]);
      if (a[i - 1][j] == '1') {
        // trace(i - 1, j, a[i - 1][j]);
        hi = j;
      }
    }
    for (int j = M; j >= 1; j--) {
      if (a[i - 1][j] == '1') {
        lo = j;
      }
    }
    amin(f[i][0], f[i - 1][0] + 2 * hi + 1);
    amin(f[i][0], f[i - 1][1] + M + 2);
    amin(f[i][1], f[i - 1][1] + 2 * (M + 1 - lo) + 1);
    amin(f[i][1], f[i - 1][0] + M + 2);
  }
}

int main() {
  // ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
