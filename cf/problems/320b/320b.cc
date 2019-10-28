/* created   : 2019-10-27 10:34:17
 * accepted  : 2019-10-27 12:49:14
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

const int N = 120;
vector<pair<int, int>> st;
vector<int> g[N];
bool use[N];

bool check(int i, int j) {
  int ret = 0;
  ret |= (st[j].x < st[i].x && st[i].x < st[j].y);
  ret |= (st[j].x < st[i].y && st[i].y < st[j].y);
  return ret;
}

bool dfs(int s, int t) {
  trace("dfs", s, t);
  if (use[s]) {
    return false;
  }
  if (s == t) {
    return true;
  }
  use[s] = 1;
  for (int i = 0; i < st.size(); i++) {
    if (use[i]) {
      continue;
    }
    if (check(s, i)) {
      if (dfs(i, t)) {
        return true;
      }
    }
  }
  // use[s] = 0;
  return false;
}

void solve() {
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    int op, a, b; cin >> op >> a >> b;
    if (op == 1) {
      // trace(, a, b);
      st.emplace_back(a, b);
    }
    else {
      a--, b--;
      memset(use, 0, sizeof(use));
      trace("OP2", a, b);
      cout << (dfs(a, b) ? "YES" : "NO") << '\n';
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
