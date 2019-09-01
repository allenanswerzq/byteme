#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

const int mod = 1e9 + 7;

int rec(int n, int x, int y) {
  if (n == 0) {
    return x == 0;
  }
  int ans = 0;
  for (int i = 1; i < y; i++) {
    ans += rec(n - 1, x - i, i);
    ans %= mod;
  }
  return ans;
}

void solve() {
  int n, s;
  cin >> n >> s;
  int ans = rec(n, s, s);
  cout << ans % mod << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
