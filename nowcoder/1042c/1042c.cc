/* created   : 2019-12-19 23:59:53
 * accepted  : 2019-12-28 09:25:04
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

int amax(int& a, int b) {
  return max(a, b);
}

int f[22][820];
int d[220][22][820];
int a[220];
int b[220];
vector<int> path;
int sum_a;
int sum_b;
int tc;
int n;
int m;

void get_path(int i, int j, int k) {
  if (i < 0 || j == 0) return;
  int last = d[i][j][k];
  get_path(last - 1, j - 1, k - (a[last] - b[last]));
  path.push_back(last);
  sum_a += a[last];
  sum_b += b[last];
}

void solve() {
  memset(f, 0xcf, sizeof(f));
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
  }
  f[0][400] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      for (int k = 0; k <= 800; k++) {
        // 1) do not choose the ith item
        amax(f[j][k], f[j - 1][k]);
        d[i][j][k] = d[i - 1][j][k];
      }
    }
    for (int j = m; j >= 1; j--) {
      for (int k = 0; k <= 800; k++) {
        // 2) choose the ith item
        int diff = k - (a[i] - b[i]);
        if (!(0 <= diff && diff <= 800)) continue;
        if (f[j][k] < f[j - 1][diff] + a[i] + b[i]) {
          f[j][k] = f[j - 1][diff] + a[i] + b[i];
          d[i][j][k] = i;
        }
      }
    }
  }
  int mi_sub = 1 << 30;
  for (int k = 0; k < 820; k++) {
    if (f[m][k] >= 0) {
      mi_sub = min(mi_sub, abs(k - 400));
    }
  }
  int mx_add = -(1 << 30);
  int best = 0;
  for (int k = 0; k < 820; k++) {
    if (abs(k - 400) == mi_sub && f[m][k] > mx_add) {
      mx_add = f[m][k];
      best = k;
    }
  }
  trace(mt(a, n + 1));
  trace(mt(b, n + 1));
  trace(mi_sub, best);
  sum_a = 0;
  sum_b = 0;
  path.clear();
  get_path(n, m, best);
  cout << "Jury #" << tc << '\n';
  cout << "Best jury has value " << sum_a
       << " for prosecution and value " << sum_b
       << " for defence:\n";
  for (int i = 0; i < (int) path.size(); i++) {
    cout << " " << path[i];
  }
  cout << "\n\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  while (cin >> n >> m && n && m) {
    tc++;
    solve();
  }
  return 0;
}

