/* created   : 2020-12-30 22:39:19
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
  string S; cin >> S;
  vector<int> z = z_function(S);
  int n = S.size();
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (i + z[i] == n) {
      ans.push_back(z[i]);
    }
  }
  sort(all(ans));
  for (int i = 0; i < ans.size(); i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << ans[i];
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
