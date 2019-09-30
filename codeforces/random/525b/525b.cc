/* created   : 2019-09-15 16:36:45
 * accepted  : 2019-09-15 16:51:41
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
  string s; cin >> s;
  int k; cin >> k;
  int n = s.size();
  vector<int> cnt(n + 1);
  for (int i = 0; i < k; i++) {
    int x; cin >> x;
    int y = n - x + 1;
    x--, y--;
    // NOTE(zq7): cool trick to handle intervals again.
    cnt[x]++;
    cnt[y + 1]++;
  }
  for (int i = 0; i < n / 2; i++) {
    cnt[i] += (i - 1 >= 0 ? cnt[i - 1] : 0);
    if (cnt[i] % 2) {
      swap(s[i], s[n - i - 1]);
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
