/* created   : 2020-12-30 22:12:15
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

vector<int> z_function(const string& s) {
  int n = (int) s.size();
  vector<int> z(n);
  int x = 0, y = 0;
  for (int i = 1; i < n; ++i) {
    z[i] = max(0, min(z[i - x], y - i + 1));
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      x = i;
      y = i + z[i];
      z[i]++;
    }
  }
  return z;
}

void solve() {
  string S, P; cin >> S >> P;
  string t = P + '#' + S;
  vector<int> z = z_function(t);
  int ans = 0;
  for (int i = P.size(); i < z.size(); i++) {
    if (z[i] == P.size()) {
      ans++;
    }
  }
  trace(t, z);
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
