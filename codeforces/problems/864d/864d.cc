/* created   : 2020-02-14 22:23:06
 * accepted  : 2020-02-15 23:02:06
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
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> cnt(n + 1);
  for (int i = 1; i <= n; i++) {
    cnt[a[i]]++;
  }
  vector<int> need;
  for (int i = 1; i <= n; i++) {
    if (cnt[i] == 0) {
      need.push_back(i);
    }
  }
  int k = 0;
  vector<bool> seen(n + 1);
  cout << need.size() << '\n';
  for (int i = 1; i <= n; i++) {
    if (cnt[a[i]] > 1) {
      if (need[k] > a[i] && seen[a[i]] == false) {
        seen[a[i]] = true;
        continue;
      }
      cnt[a[i]]--;
      a[i] = need[k++];
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << a[i] << (i == n ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
