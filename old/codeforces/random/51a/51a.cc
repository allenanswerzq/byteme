/*
 * Name        : 51a
 * Creat       : Thu Jul 11 12:30:19 CST 2019
 * Accept      : Thu Jul 11 14:19:19 CST 2019
 * Author      : landcold7
 * Description : Action speaks louder more than words
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

void solve2() {
  int n;
  cin >> n;
  set<string> st;
  for (int i = 0; i < n; ++i) {
    if (i > 0) {
      string x;
      cin >> x;
    }
    string s, t;
    cin >> s >> t;
    s += t[1];
    s += t[0];
    t = s;
    for (int j = 1; j < 4; ++j) {
      string cur = s.substr(j) + s.substr(0, j);
      if (cur < t) {
        t = cur;
      }
    }
    st.insert(t);
  }
  trace(st);
  cout << sz(st) << "\n";
}

void solve() {
  int n;
  cin >> n;
  vector<string> v;
  for (int i = 0; i < n; ++i) {
    if (i > 0) {
      string x;
      cin >> x;
    }
    string s, t;
    cin >> s >> t;
    reverse(t.begin(), t.end());
    s += t;
    bool ok = 1;
    for (auto x : v) {
      for (int j = 0; j < 4; ++j) {
        string cur = s.substr(j) + s.substr(0, j);
        if (cur == x) {
          ok = 0;
          break;
        }
      }
      if (!ok) {
        break;
      }
    }
    if (ok) {
      v.push_back(s);
    }
  }
  trace(v);
  cout << sz(v) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
