/* created   : 2020-02-06 22:02:17
 * accepted  : 2020-02-06 23:16:38
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n, m; cin >> n >> m;
  vector<string> a(n);
  unordered_map<string, int> cnt;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      string x;
      for (int k = 0; k < m; k++) {
        if (a[i][k] == a[j][k]) {
          x.push_back(a[i][k]);
        }
        else {
          char ch;
          for (auto t : {'S', 'T', 'E'}) {
            if (a[i][k] != t && a[j][k] != t) {
              ch = t;
              break;
            }
          }
          x.push_back(ch);
        }
      }
      ans += cnt[x];
    }
  }
  cout << ans / 3 << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
