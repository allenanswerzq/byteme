/*
 * Creat   : Sun Jul 14 09:28:25 CST 2019
 * Accept  : Sun Jul 14 10:18:38 CST 2019
 * Author  : landcold7
 */
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define sz(x) ((int)(x).size())
#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;

bool removal(string s, string t) {
  int lo = 0;
  for (int i = 0; i < sz(s); ++i) {
    if (s[i] == t[lo]) {
      lo++;
    }
  }
  return lo == sz(t);
}

void solve() {
  string s, t;
  cin >> s >> t;
  assert(s != t);
  // Removal
  if (removal(s, t)) {
    cout << "automaton" << "\n";
    return;
  }
  // Array
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  if (s == t) {
    cout << "array" << "\n";
    return;
  }
  trace(s, t);
  // Both
  if (removal(s, t)) {
    cout << "both" << "\n";
    return;
  }
  // Need tree
  cout << "need tree" << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
