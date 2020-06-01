/* created   : 2020-05-31 15:38:43
 * accepted  : 2020-05-31 18:08:23
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

template <int N>
struct Discreter {
  vector<int> e;
  vector<int> t;
  int n;

  Discreter(vector<int>& v) {
    e = v;
    sort(all(e));
    e.erase(unique(all(e)), e.end());
    n = (int) e.size();
    for (int i = 0; i < N; i++) {
      int x = upper_bound(all(e), i) - e.begin();
      t.push_back(x);
    }
  }

  // Given a original value, returns the discreted value.
  int get(int x) {
    return t[x];
  }

  // Given a discreted value, return the original value.
  int old(int x) {
    return e[x - 1];
  }
};

const int N = 1010;

int ps[N][N];

void solve() {
  int c, n; cin >> c >> n;
  vector<pair<int, int>> grass;
  vector<int> val;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int x, y; cin >> x >> y;
      val.push_back(x);
      val.push_back(y);
      grass.push_back({x, y});
    }
  }

  const int INF = 1e4 + 7;
  Discreter<INF> dis(val);
  for (int i = 0; i < n; i++) {
    int x = grass[i].x;
    int y = grass[i].y;
    ps[dis.get(x)][dis.get(y)]++;
  }

  int m = dis.n;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= m; j++) {
      ps[i][j] += ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1];
    }
  }

  auto check = [&](int md) {
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= m; j++) {
        int x = 0, y = 0;
        if (dis.old(i) - md >= 0) {
          x = dis.get(dis.old(i) - md);
        }
        if (dis.old(j) - md >= 0) {
          y = dis.get(dis.old(j) - md);
        }
        if (ps[i][j] - ps[x][j] - ps[i][y] + ps[x][y] >= c) {
          return true;
        }
      }
    }
    return false;
  };

  int lo = 0;
  int hi = INF;
  while (lo + 1 < hi) {
    int md = lo + (hi - lo) / 2;
    trace(lo, hi, md);
    if (check(md)) {
      hi = md;
    }
    else {
      lo = md;
    }
  }
  cout << hi << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
