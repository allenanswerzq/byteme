/* created   : 2020-03-29 22:51:35
 * accepted  : 2020-03-30 14:38:37
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n, m, x;
  cin >> n >> m >> x;
  vector<string> a(n);
  set<char> mp;
  vector<pair<int, int>> shifts;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 'S') {
        shifts.push_back({i, j});
      } else {
        mp.insert(a[i][j]);
      }
    }
  }
  trace(shifts, mp);
  vector<double> dist(27, 1e9);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 'S') continue;
      double mi = dist[a[i][j] - 'a'];
      for (auto it : shifts) {
        double d = (i - it.x) * (i - it.x) +
                   (j - it.y) * (j - it.y);
        mi = min(mi, sqrt(d));
      }
      dist[a[i][j] - 'a'] = mi;
    }
  }
  int q;
  cin >> q;
  string s;
  cin >> s;
  trace(dist);
  int ans = 0;
  for (int i = 0; i < q; i++) {
    if ('a' <= s[i] && s[i] <= 'z') {
      if (!mp.count(s[i])) {
        cout << -1 << '\n';
        return;
      }
    }
    else if (shifts.empty() || !mp.count(tolower(s[i]))) {
      cout << -1 << '\n';
      return;
    }
    else if (dist[tolower(s[i]) - 'a'] > x) {
      ans++;
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
