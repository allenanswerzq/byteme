/* created   : 2020-01-10 23:41:22
 * accepted  : 2020-01-11 10:19:09
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

int rec(vector<int>&a, int bit) {
  if (a.empty() || bit < 0) {
    return 0;
  }
  vector<int> one, zero;
  for (int i = 0; i < (int) a.size(); i++) {
    if (a[i] & (1ll << bit)) {
      one.push_back(a[i]);
    }
    else {
      zero.push_back(a[i]);
    }
  };
  if (one.empty()) {
    return rec(zero, bit - 1);
  }
  else if (zero.empty()) {
    return rec(one, bit - 1);
  }
  else {
    return min(rec(one, bit - 1), rec(zero, bit - 1)) + (1 << bit);
  }
}

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cout << rec(a, 30) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
