/* created   : 2020-06-11 06:22:13
 * accepted  : 2020-06-11 06:45:41
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

int go(vector<int>& a) {
  int ans = 0;
  vector<int> stk;
  a.push_back(-1);
  for (int i = 0; i < a.size(); i++) {
    if (stk.empty() || a[i] >= a[stk.back()]) {
      stk.push_back(i);
      continue;
    }
    while (stk.size() && a[stk.back()] >= a[i]) {
      int height = a[stk.back()];
      stk.pop_back();
      int hi = i;
      int lo = (stk.empty() ? -1 : stk.back());
      ans = max(ans, (hi - lo - 1) * height);
    }
    stk.push_back(i);
  }
  trace(ans, a);
  return ans;
}


void solve() {
  int n, m; cin >> n >> m;
  vector<vector<char>> s(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> s[i][j];
    }
  }
  vector<vector<int>> a(n + 1, vector<int>(m));
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < m; j++) {
      a[i][j] = (s[i - 1][j] == 'F' ? a[i - 1][j] + 1 : 0);
    }
  }
  trace(a);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, go(a[i]));
  }
  cout << 3 * ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
