/* created   : 2020-02-23 15:42:40
 * accepted  : 2020-02-23 17:24:56
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
  string s, t; cin >> s >> t;
  int n = s.size();
  string st = s;
  sort(all(st));
  // azxxxxxxbxxxxxb
  // abxxxxxxzxxxxxb
  // abxxxxxxbxxxxxz
  int pos = -1;
  for (int i = 0; i < n; i++) {
    if (st[i] != s[i]) {
      pos = i;
      break;
    }
  }
  if (pos != -1) {
    int far = -1;
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == st[pos]) {
        far = i;
        break;
      }
    }
    assert(far != -1);
    swap(s[far], s[pos]);
  }
  if (s < t) {
    cout << s << '\n';
  }
  else {
    cout << "---" << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  for (int i = 0; i < tc; i++) {
    solve();
  }
  return 0;
}
