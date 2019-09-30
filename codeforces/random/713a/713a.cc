/* created   : 2019-09-13 16:41:25
 * accepted  : 2019-09-13 16:59:56
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

const int N = (1 << 18) + 7;

int pat(ll x) {
  int ans = 0;
  int p = 1;
  while (x) {
    int d = ((x % 10) % 2);
    ans = d * p + ans;
    p *= 2;
    x /= 10;
  }
  return ans;
}

void solve() {
  int n; cin >> n;
  vector<int> pattern(N);
  for (int i = 0; i < n; i++) {
    char c; cin >> c;
    if (c == '+') {
      ll x; cin >> x;
      trace(i, x, pat(x));
      pattern[pat(x)]++;
    }
    else if (c == '-') {
      ll x; cin >> x;
      trace(i, x, pat(x));
      pattern[pat(x)]--;
    }
    else {
      string x; cin >> x;
      int match = 0;
      for (int j = 0; j < (int) x.size(); j++) {
        match = match * 2 + (x[j] - '0');
      }
      trace(i, x, match);
      cout << pattern[match] << '\n';
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
