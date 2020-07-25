/* created   : 2020-03-09 11:46:26
 * accepted  : 2020-03-09 12:18:31
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
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    vector<int> cnt(n);
    int best = a[i];
    for (int j = i; j < n; j++) {
      int color = a[j];
      cnt[color]++;
      if (cnt[color] > cnt[best]) {
        best = color;
      }
      else if (cnt[color] == cnt[best] && color < best) {
        best = color;
      }
      trace(i, j, best);
      ans[best]++;
    }
    trace(cnt);
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << (i == n - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
