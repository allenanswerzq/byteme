/* created   : 2020-08-23 11:45:06
 * accepted  : 2020-08-23 12:00:49
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

int n, a, b, c;
bool ok = false;

bool dfs(int u, vector<int>& path) {
  if (u == n) {
    int mx = path[0];
    int ca = 0;
    set<int> st;
    for (int i = 0; i < n; i++) {
      if (path[i] >= mx) {
        ca++;
        st.insert(i);
      }
      mx = max(mx, path[i]);
    }
    mx = path[n - 1];
    int cb = 0;
    int cc = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (path[i] >= mx) {
        cb++;
        if (st.count(i)) {
          cc++;
        }
      }
      mx = max(mx, path[i]);
    }
    bool flag = (ca == a && cb == b && cc == c);
    ok = flag;
    return flag;
  }
  for (int i = 1; i <= n; i++) {
    path.push_back(i);
    if (dfs(u + 1, path)) return true;
    path.pop_back();
  }
  return false;
}

void solve() {
  cin >> n >> a >> b >> c;
  vector<int> path;
  dfs(0, path);
  if (!ok) {
    cout << "IMPOSSIBLE\n";
  }
  else {
    for (int i = 0; i < (int) path.size(); i++) {
      if (i > 0) cout << " ";
      cout << path[i];
    }
    cout << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
