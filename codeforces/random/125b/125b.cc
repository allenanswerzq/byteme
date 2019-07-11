/*
 * Name        : 125b
 * Creat       : Thu Jul 11 15:59:21 CST 2019
 * Accept      : Thu Jul 11 16:11:54 CST 2019
 * Author      : landcold7
 * Motivation  : Action speaks louder more than words
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

void solve() {
  string s;
  cin >> s;
  vector<string> stk;
  for (int i = 0; i < sz(s); ) {
    if (s.substr(i, 2) == "</") {
      string a = s.substr(i + 2, 1);
      string b = stk.back();
      trace(i, a, b);
      if (a == b) {
        stk.pop_back();
        string sp = string(2 * sz(stk), ' ');
        cout << sp << "</" << b << ">" << "\n";
      }
      else {
        // stk.push_back(a);
        assert(false);
      }
      i += 4;
    }
    else if (s.substr(i, 1) == "<") {
      string a = s.substr(i + 1, 1);
      string sp = string(2 * sz(stk), ' ');
      cout << sp << "<" << a << ">" << "\n";
      stk.push_back(a);
      i += 3;
    }
    else {
      assert(false);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
