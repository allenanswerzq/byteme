/* created   : 2019-10-20 14:35:06
 * accepted  : 2019-10-20 19:24:21
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

void solve() {
  int n; cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  string s; cin >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      int j = i + 1;
      while (j < n && s[j] == '1') {
        j++;
      }
      sort(v.begin() + i, v.begin() + j + 1);
      i = j;
    }
  }
  trace(v);
  for (int i = 0; i < n - 1; i++) {
    if (v[i] > v[i + 1]) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES" << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
