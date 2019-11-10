/* created   : 2019-11-09 20:08:09
 * accepted  : 2019-11-09 20:42:22
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

const int mod = 998244353;

int mul(int a, int b) {
  return (int) ((ll) a * b % mod);
}

int power(int a, ll b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

void solve() {
  int n; cin >> n;
  const int N = 1e5 + 7;
  vector<int> cnt(N);
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    if (i == 0 && x != 0) {
      cout << 0 << '\n';
      return;
    }
    cnt[x]++;
  }
  // assert(cnt[0] == 1);
  if (cnt[0] != 1) {
    cout << 0 << '\n';
    return;
  }
  int ans = 1;
  for (int i = 1; i < N; i++) {
    int cur = cnt[i];
    int last = cnt[i - 1];
    if (cur > 0 && last > 0) {
      ans = mul(ans, power(last, cur));
    }
    if (cur > 0 && last == 0) {
      cout << 0 << '\n';
      return;
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
