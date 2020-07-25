/* created   : 2020-04-28 11:48:47
 * accepted  : 2020-04-28 15:51:32
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n; cin >> n;
  if (n == 1) {
    cout << -1 << "\n";
    return;
  }
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(all(a));
  vector<int> ans;
  {
    int d = (a[n - 1] - a[0]) / (n - 1);
    bool ok = true;
    for (int i = 0; i + 1 < n; i++) {
      if (a[i + 1] - a[i] != d) {
        ok = false;
        break;
      }
    }
    if (ok) {
      ans.push_back(a[0] - d);
      ans.push_back(a[n - 1] + d);
    }
  }
  {
    int d = (a[n - 1] - a[0]) / n;
    int lo = 0;
    while (lo + 1 < n && a[lo + 1] == a[lo] + d) {
      lo++; 
    }
    int hi = n - 1;
    while (hi >= 1 && a[hi - 1] == a[hi] - d) {
      hi--;
    }
    if (lo + 1 == hi && a[lo] + d == a[hi] - d) {
      ans.push_back(a[lo] + d);
    }
  }
  sort(all(ans));
  ans.erase(unique(all(ans)), ans.end());
  cout << ans.size() << "\n";
  for (int i = 0; i < (int) ans.size(); i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << ans[i];
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
