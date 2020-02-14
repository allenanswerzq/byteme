/* created   : 2020-02-13 22:15:13
 * accepted  : 2020-02-14 21:52:46
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

const int mod = 1e9 + 7;

void add(int& a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

void sub(int& a, int b) {
  a -= b;
  if (a < 0) {
    a += mod;
  }
}

int mul(int a, int b) { return (int)((ll)a * b % mod); }

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
  string s; cin >> s;
  int n = s.size();
  vector<int> a;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'a') {
      cnt++;
    }
    else if (s[i] == 'b') {
      if (cnt > 0) {
        a.push_back(cnt);
      }
      cnt = 0;
    }
  }
  if (cnt > 0) {
    a.push_back(cnt);
  }
  if (a.empty()) {
    cout << 0 << '\n';
    return;
  }
  trace(a);
  int ans = a[0] % mod;
  for (int i = 1; i < a.size(); i++) {
    int cur = 0;
    add(cur, mul(a[i], ans));
    add(cur, a[i]);
    add(ans, cur);
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
