/* created   : 2020-05-23 12:18:06
 * accepted  : 2020-05-24 13:36:08
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

bool go(vector<int>& a, int t, ll& ans) {
  int na = a.size();
  if (t % na) return false;
  vector<int> s(na + 1);
  int avg = t / na;
  for (int i = 0; i < na; i++) {
    s[i + 1] = s[i] + a[i] - avg;
  }
  sort(s.begin() + 1, s.end());
  ans = 0;
  for (int i = 1; i <= na / 2; i++) {
    ans += s[na - i + 1] - s[i];
  }
  return true;
}

void solve() {
  int n, m, t; cin >> n >> m >> t;
  vector<int> row(n), col(m);
  for (int i = 0; i < t; i++) {
    int x, y; cin >> x >> y;
    x--, y--;
    row[x]++;
    col[y]++;
  }
  // trace(row, col);
  ll ans_x = 0;
  bool x = go(col, t, ans_x);
  ll ans_y = 0;
  bool y = go(row, t, ans_y);
  if (x && y) {
    cout << "both ";
    cout << ans_x + ans_y << "\n";
  }
  else if (x) {
    cout << "column" << " " << ans_x << "\n";
  }
  else if (y) {
    cout << "row" << " " << ans_y << "\n";
  }
  else {
    cout << "impossible\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
