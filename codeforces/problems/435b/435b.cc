/* created   : 2020-02-26 22:10:18
 * accepted  : 2020-02-26 23:37:58
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
  string s; cin >> s;
  int k; cin >> k;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    pair<char, int> mx = {'0', i + 1};
    for (int j = i + 1; j < i + k + 1 && j < n; j++) {
      if (mx.x < s[j]) {
        mx = {s[j], j};
      }
    }
    trace(i, mx);
    if (mx.y < n && mx.x > s[i]) {
      for (int w = mx.y; w > i; w--) {
        swap(s[w], s[w - 1]);
      }
      k -= (mx.y - i);
    }
  }
  cout << s << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
