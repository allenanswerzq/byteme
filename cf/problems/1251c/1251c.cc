/* created   : 2020-02-05 14:18:19
 * accepted  : 2020-02-05 15:18:55
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
  string a; cin >> a;
  vector<char> even;
  vector<char> odd;
  for (int i = 0; i < (int) a.size(); i++) {
    if (a[i] % 2 == 0) {
      even.push_back(a[i]);
    }
    else {
      odd.push_back(a[i]);
    }
  }
  int p = 0;
  int q = 0;
  string ans;
  while (p < even.size() && q < odd.size()) {
    if (even[p] <= odd[q]) {
      ans += even[p++];
    }
    else {
      ans += odd[q++];
    }
  }
  while (p < even.size()) {
    ans += even[p++];
  }
  while (q < odd.size()) {
    ans += odd[q++];
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  for (int i = 0; i < tc; i++) {
    solve();
  }
  return 0;
}
