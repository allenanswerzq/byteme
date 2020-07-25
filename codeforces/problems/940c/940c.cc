/* created   : 2020-03-01 15:10:24
 * accepted  : 2020-03-01 16:10:24
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

bool go(vector<int>& st, char ch, char* ans) {
  for (int i = 0; i < 26; i++) {
    if (st[i] > 0 && (char)('a' + i) > ch) {
      *ans = (char)('a' + i);
      return true;
    }
  }
  return false;
}

void solve() {
  int n, k; cin >> n >> k;
  string s; cin >> s;
  vector<int> st(26);
  char mi = 'z';
  for (int i = 0; i < n; i++) {
    st[s[i] - 'a']++;
    mi = min(mi, s[i]);
  }
  if (n < k) {
    for (int i = n; i < k; i++) {
      s.push_back(mi);
    }
    cout << s << '\n';
  }
  else {
    for (int i = k - 1; i >= 0; i--) {
      char big;
      if (go(st, s[i], &big)) {
        s[i] = big;
        trace(i, big, mi);
        for (int j = i + 1; j < n; j++) {
          s[j] = mi;
        }
        cout << s.substr(0, k) << '\n';
        return;
      }
    }
    // must return at line 50.
    assert(false);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
