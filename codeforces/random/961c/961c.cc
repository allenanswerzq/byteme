/*
 * created   : 2019-08-01 17:08:58
 * accepted  : 2019-08-01 17:23:03
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

int get(vector<string>& a, int op) {
  int n = a.size();
  int x = (op == 0 ? 0 : 1);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if ((a[i][j] - '0') != x) {
        ans++;
      }
      x ^= 1;
    }
  }
  return ans;
}

void solve() {
  int n;
  cin >> n;
  vector<vector<string>> a(4, vector<string>(n));
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  trace(a);
  vector<pair<int, int>> b(4);
  for (int i = 0; i < 4; i++) {
    b[i].x = get(a[i], 0);
    b[i].y = get(a[i], 1);
  }
  trace(b);
  int ans = (1 << 30);
  for (int i = 0; i < 4; i++) {
    for (int j = i + 1; j < 4; j++) {
      int t = 0;
      t += b[i].x;
      t += b[j].x;
      for (int k = 0; k < 4; k++) {
        if (k != i && k != j) {
          t += b[k].y;
        }
      }
      ans = min(ans, t);
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
