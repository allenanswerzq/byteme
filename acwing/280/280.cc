/* created   : 2020-07-12 09:01:05
 * accepted  : 2020-07-12 11:15:00
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define pii pair<int, int>

void amax(int& a, int b) { a = max(a, b); }

const int N = 220;
const int M = 810;
const int B = 400;
int f[N][22][M];
int p[N], d[N];
int n;
int m;

void solve() {
  for (int i = 1; i <= n; i++) {
    cin >> p[i] >> d[i];
  }
  memset(f, -0x3f, sizeof(f));
  f[0][0][B] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      for (int k = 0; k < M; k++) {
        f[i][j][k] = f[i - 1][j][k];
        int t = k - (p[i] - d[i]);
        if (!(0 <= t && t < M)) continue;
        if (j < 1) continue;
        amax(f[i][j][k], f[i - 1][j - 1][t] + p[i] + d[i]);
      }
    }
  }
  int v = 0;
  // Compute the mininum |D - P|
  while (f[n][m][B - v] < 0 && f[n][m][B + v] < 0) v++;
  // Compute the maxinum |D + P|
  if (f[n][m][B - v] > f[n][m][B + v]) {
   v = B - v;
  }
  else {
   v = B + v;
  }
  vector<int> path;
  while (n && m) {
    if (f[n][m][v] == f[n - 1][m][v]) {
      n--;
    }
    else {
      path.push_back(n);
      v -= (p[n] - d[n]);
      n--, m--;
    }
  }
  int sp = 0, sd = 0;
  for (auto id : path) {
    sp += p[id];
    sd += d[id];
  }
  cout << "Best jury has value " << sp
       << " for prosecution and value " << sd << " for defence:\n";
  sort(all(path));
  for (int i = 0; i < (int) path.size(); i++) {
    if (i >= 0) {
      cout << " ";
    }
    cout << path[i];
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  while (cin >> n >> m && n && m) {
    cout << "Jury #" << tc++ << "\n";
    solve();
  }
  return 0;
}
