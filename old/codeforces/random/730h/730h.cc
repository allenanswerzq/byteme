/* created   : 2019-08-17 21:17:39
 * accepted  : 2019-08-17 22:03:22
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<string> b(m);
  set<int> st;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    x--;
    st.insert(x);
    b[i] = a[x];
  }
  trace(a, b);
  int nb = (int) b[0].size();
  bool same_length = 1;
  for (int i = 1; i < m; i++) {
    if ((int) b[i].size() != nb) {
      same_length = 0;
      break;
    }
  }
  if (!same_length) {
    cout << "No" << '\n';
    return;
  }
  vector<bool> use(nb);
  for (int i = 0; i < nb; i++) {
    bool ok = 1;
    for (int j = 0; j < m; j++) {
      if (b[j][i] != b[0][i]) {
        ok = 0;
        break;
      }
    }
    use[i] = ok;
  }
  string ans;
  for (int i = 0; i < nb; i++) {
    ans += (use[i] ? b[0][i] : '?');
  }
  for (int i = 0; i < n; i++) {
    if (!st.count(i) && (int) a[i].size() == nb) {
      bool same = 1;
      for (int j = 0; j < nb; j++) {
        if (!(ans[j] == a[i][j] || ans[j] == '?')) {
          same = 0;
          break;
        }
      }
      if (same) {
        trace(a[i], ans);
        cout << "No" << '\n';
        return;
      }
    }
  }
  cout << "Yes" << '\n';
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
