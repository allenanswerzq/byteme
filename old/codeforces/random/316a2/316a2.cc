/* created   : 2019-08-19 23:18:19
 * accepted  : 2019-08-19 23:50:11
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

void solve() {
  string s;
  cin >> s;
  set<char> st;
  bool letter = ('A' <= s[0] && s[0] <= 'J');
  bool question = (s[0] == '?');
  int a = 0;
  for (int i = 1; i < (int) s.size(); i++) {
    if (s[i] == '?') {
      a++;
    }
    else if ('A' <= s[i] && s[i] <= 'J') {
      st.insert(s[i]);
    }
  }
  int ns = st.size();
  if (st.count(s[0])) {
    ns--;
  }
  ll ans = ((letter || question) ? 9 : 1);
  trace(ns, a, letter);
  int k = (letter ? 9 : 10);
  for (int i = 0; i < ns; i++) {
    ans *= k--;
  }
  cout << ans;;
  for (int i = 0; i < a; i++) {
    cout << '0';
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
