/* created   : 2019-12-28 15:20:24
 * accepted  : 2019-12-28 16:20:49
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void amin(int& a, int b) { a = min(a, b); }
void amax(int& a, int b) { a = max(a, b); }

const int N = 200;
int fmx[N][N];
int fmi[N][N];
char c[N];
int a[N];
int n;

// t  t x x  t t x x
// -7 4 2 5 -7 4 2 5
// t -7 t 4 x 2 x 5 t -7 t 4 x 2 x 5
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
    cin >> a[i];
  }
  for (int i = n + 1; i <= 2 * n; i++) {
    c[i] = c[i - n];
    a[i] = a[i - n];
  }
  memset(fmx, 0xcf, sizeof(fmx));
  memset(fmi, 0x3f, sizeof(fmi));
  for (int i = 1; i <= 2 * n; i++) {
    fmx[i][i] = a[i];
    fmi[i][i] = a[i];
  }
  for (int len = 2; len <= n; len++) {
    for (int l = 1; l + len - 1 <= 2 * n; l++) {
      int r = l + len - 1;
      for (int k = l; k + 1 <= r; k++) {
        if (c[k + 1] == 't') {
          amax(fmx[l][r], fmx[l][k] + fmx[k + 1][r]);
          amin(fmi[l][r], fmi[l][k] + fmi[k + 1][r]);
        }
        else {
          amax(fmx[l][r], fmx[l][k] * fmx[k + 1][r]);
          amax(fmx[l][r], fmi[l][k] * fmi[k + 1][r]);
          amin(fmi[l][r], fmx[l][k] * fmx[k + 1][r]);
          amin(fmi[l][r], fmi[l][k] * fmi[k + 1][r]);
          amin(fmi[l][r], fmx[l][k] * fmi[k + 1][r]);
          amin(fmi[l][r], fmi[l][k] * fmx[k + 1][r]);
        }
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, fmx[i][i + n - 1]);
  }
  cout << ans << '\n';
  vector<int> v;
  for (int i = 1; i <= n; i++) {
    if (ans == fmx[i][i + n - 1]) {
      v.push_back(i);
    }
  }
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << (i == v.size() - 1 ? '\n' : ' ');;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
