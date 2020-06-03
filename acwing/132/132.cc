/* created   : 2020-06-03 19:04:55
 * accepted  : 2020-06-03 19:10:31
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

const int N = 6e4 + 7;
ll f[N];

ll rec(int x) {
  if (x == 0 || x == 1) return 1;
  if (f[x] > 0) return f[x];
  ll ans = 0;
  for (int i = 1; i <= x; i++) {
    ans += rec(i - 1) * rec(x - i);
  }
  return f[x] = ans;
}

void solve() {
  int n; cin >> n;
  memset(f, -1, sizeof(f));
  cout << rec(n) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
