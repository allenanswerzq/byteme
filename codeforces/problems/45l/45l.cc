/* created   : 2020-04-05 09:22:23
 * accepted  : 2020-04-05 09:39:02
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  int neg = 0;
  int zero = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    neg += a[i] < 0;
    zero += a[i] == 0;
  }
  sort(all(a));
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (a[i] > 0) {
      ans.push_back(a[i]);
    }
  }
  if (neg % 2 == 0) {
    for (int i = 0; i < n; i++) {
      if (a[i] < 0) {
        ans.push_back(a[i]);
      }
    }
  }
  else {
    for (int i = 0; i + 1 < n; i += 2) {
      if (a[i] < 0 && a[i + 1] < 0) {
        ans.push_back(a[i]);
        ans.push_back(a[i + 1]);
      }
    }
  }
  if (ans.empty() && zero >= 1) {
    ans.push_back(0);
  }
  if (ans.empty()) {
    assert(neg > 0);
    ans.push_back(a[0]);
  }
  assert(!ans.empty());
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << (i == ans.size() - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
