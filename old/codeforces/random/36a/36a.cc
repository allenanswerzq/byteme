/* created   : 2019-08-21 11:39:00
 * accepted  : 2019-08-21 11:49:02
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
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n;
  string s;
  cin >> n >> s;
  vector<int> a;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      a.push_back(i);
    }
  }
  int d = -1;
  for (int i = 0; i < (int) a.size() - 1; i++) {
    if (i == 0) {
      d = a[i + 1] - a[i];
    }
    else if (a[i + 1] - a[i] != d) {
      d = -1;
      break;
    }
  }
  cout << (d == -1 ? "NO" : "YES") << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
