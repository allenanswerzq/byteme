/* created   : 2020-03-16 10:17:38
 * accepted  : 2020-03-16 11:06:44
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
typedef pair<int, int> pii;

unordered_set<string> st;

void rec(string& cur) {
  trace(cur);
  // if ((int) cur.size() > 0 && !st.count(cur)) {
  //   cout << cur << '\n';
  //   exit(0);
  // }
  if ((int) cur.size() > 6) {
    return;
  }
  string tmp = cur;
  for (int i = tmp.back() - 'a'; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      tmp.back() = (char)('a' + i);
      tmp.push_back((char)('a' + j));
      trace(i, j, tmp);
      // if (!st.count(tmp)) {
      //   cout << tmp << '\n';
      //   exit(0);
      // }
      tmp.pop_back();
    }
  }
  for (int i = 0; i < 26; i++) {
    cur.push_back((char)('a' + i));
    rec(cur);
    cur.pop_back();
  }
}

void solve() {
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    int m = s.size();
    for (int j = 0; j < m; j++) {
      for (int k = j; k < m; k++) {
        st.insert(s.substr(j, k - j + 1));
      }
    }
  }
  for (char c = 'a'; c <= 'z'; c++) {
    string s;
    s += c;
    if (!st.count(s)) {
      cout << s << '\n';
      return;
    }
  }
  for (char c = 'a'; c <= 'z'; c++) {
    string s;
    s += c;
    rec(s);
  }
  assert(false);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
