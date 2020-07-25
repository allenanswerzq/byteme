/* created   : 2020-02-09 11:35:44
 * accepted  : 2020-02-09 13:14:29
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

void solve2() {
  int n, r; cin >> n >> r;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int last = -1;
  int ans = 0;
  while (last < n - 1) {
    int lo = max(-1, last - r + 1);
    int hi = last + r;
    int pos = -1;
    for (int j = min(hi, n - 1); j > lo; j--) {
      if (a[j] == 1) {
        pos = j;
        break;
      }
    }
    if (pos == -1) {
      cout << -1 << '\n';
      return;
    }
    ans++;
    last = pos + r - 1;
  }
  cout << ans << '\n';
}

void solve() {
  int n, r; cin >> n >> r;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> cnt(n + 1);
  for (int i = 0; i < n; i++) {
    if (a[i] == 1) {
      cnt[max(0, i - r + 1)]++;
      cnt[min(n, i + r)]--;
    }
  }
  for (int i = 1; i <= n; i++) {
    cnt[i] += cnt[i - 1];
  }
  for (int i = 0; i < n; i++) {
    if (cnt[i] == 0) {
      cout << -1 << '\n';
      return;
    }
  }
  trace(cnt);
  int ans = accumulate(all(a), 0);
  for (int i = 0; i < n; i++) {
    if (a[i] == 1) {
      int lo = max(0, i - r + 1);
      int hi = min(n - 1, i + r - 1);
      bool useless = true;
      for (int j = lo; j <= hi; j++) {
        if (cnt[j] == 1) {
          useless = false;
          break;
        }
      }
      if (useless) {
        ans--;
        for (int j = lo; j <= hi; j++) {
          cnt[j]--;
        }
      }
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
