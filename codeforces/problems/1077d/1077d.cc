/* created   : 2020-05-09 22:35:41
 * accepted  : 2020-05-09 22:59:54
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n, k; cin >> n >> k;
  vector<int> a(n);
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]]++;
  }
  int lo = 0;
  int hi = n + 1;
  while (lo + 1 < hi) {
    int md = lo + (hi - lo) / 2;
    int cnt = 0;
    for (auto it : mp) {
      cnt += it.y / md;
    }
    if (cnt >= k) {
      lo = md;
    }
    else {
      hi = md;
    }
  }
  trace(mp, lo, hi);
  vector<int> ans;
  for (auto it : mp) {
    for (int i = 0; i < it.y / lo; i++) {
      ans.push_back(it.x);
      if ((int) ans.size() == k) {
        goto output;
      }
    }
  }
output:
  trace(ans);
  assert((int) ans.size() == k);
  for (int i = 0; i < k; i++) {
    cout << ans[i] << (i == k - 1 ? "\n" : " ");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
