/* created   : 2020-04-27 17:07:27
 * accepted  : 2020-04-27 20:30:34
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n; 
  string s; 
  cin >> n >> s;
  int g = 0;
  vector<int> lf(n);
  for (int i = 0; i < n; i++) {
    if (s[i] == 'G') {
      g++;
      lf[i] = (i >= 1 ? lf[i - 1] : 0) + 1;
    }
    else {
      lf[i] = 0;
    }
  }
  vector<int> rt(n);
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == 'G') {
      rt[i] = (i + 1 < n ? rt[i + 1] : 0) + 1;
    }
    else {
      rt[i] = 0;
    }
  }
  trace(lf, rt);
  int ans = 0;
  bool ok = false;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'S') {
      int cur = (i >= 1 ? lf[i - 1] : 0);
      cur += (i + 1 < n ? rt[i + 1] : 0);
      if (cur < g) {
        cur++;
      }
      ans = max(ans, cur);
      ok = true;
    }
  }
  cout << (ok ? ans : g) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
