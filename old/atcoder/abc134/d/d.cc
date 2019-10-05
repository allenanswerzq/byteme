/* created   : 2019-08-11 14:45:09
 * accepted  : 2019-08-11 15:05:32
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
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  // nlogn
  vector<int> box(n + 1);
  for (int i = n; i >= 1; i--) {
    int t = 0;
    for (int j = i; j <= n; j += i) {
      t += box[j];
    }
    if (t % 2 != a[i]) {
      box[i]++;
    }
  }
  trace(box);
  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    if (box[i] == 1) {
      ans.push_back(i);
    }
    else if (box[i] > 1) {
      cout << -1 << "\n";
      return;
    }
  }
  trace(ans);
  int na = ans.size();
  cout << na << "\n";
  for (int i = 0; i < na; i++) {
    cout << ans[i] << (i == na - 1 ? "\n" : " ");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
