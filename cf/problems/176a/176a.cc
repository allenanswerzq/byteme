/* created   : 2020-04-05 09:46:35
 * accepted  : 2020-04-05 10:37:26
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

struct Node {
  int x, y, h;
};

debugstream& operator<<(debugstream& os, Node& a) {
  return os << a.x << ' ' << a.y << ' ' << a.h;
}

bool comp(const Node& a, const Node& b) {
  return a.x > b.x;
}

void solve() {
  int n, m, w; cin >> n >> m >> w;
  vector<vector<Node>> a(n);
  for (int i = 0; i < n; i++) {
    string x; cin >> x;
    vector<Node> t;
    for (int j = 0; j < m; j++) {
      int buy, sell, cnt; cin >> buy >> sell >> cnt;
      t.push_back({buy, sell, cnt});
    }
    a[i] = t;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      vector<Node> v;
      for (int k = 0; k < m; k++) {
        int x = a[i][k].x;
        int cnt = a[i][k].h;
        int y = a[j][k].y;
        v.push_back({y - x, x, cnt});
      }
      sort(all(v), comp);
      trace(v);
      int cur = 0;
      int t = w;
      for (int k = 0; k < v.size(); k++) {
        if (v[k].h > 0 && v[k].x > 0) {
          cur += min(t, v[k].h) * v[k].x;
          t -= min(t, v[k].h);
        }
      }
      trace(cur, w, t);
      ans = max(ans, cur);
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
