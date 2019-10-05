//=============================================================
// Name        : 883f
// Date        : Sun Jul  7 17:11:13 CST 2019
// Accepted    : Sun Jul  7 17:32:59 CST 2019
// Author      : landcold7
// Description : Action speaks louder more than words
//=============================================================
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define sz(x) ((int)(x).size())
#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n;
  cin >> n;
  set<string> st;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    string t;
    for (auto c : s) {
      if (c == 'h') {
        while (!t.empty() && t.back() == 'k') {
          t.pop_back();
        }
        t += 'h';
      }
      else if (c == 'u') {
        t += "oo";
      }
      else {
        t += c;
      }
    }
    st.insert(t);
  }
  trace(st);
  cout << sz(st) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
