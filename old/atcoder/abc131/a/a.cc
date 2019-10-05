/*
 * Name        : a
 * Creat       : Fri Jul 12 17:47:54 CST 2019
 * Accept      : Fri Jul 12 17:49:18 CST 2019
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
  string a;
  cin >> a;
  for (int i = 0; i < 9; ++i) {
    string t = string(2, (char)(i + '0'));
    if ((int) a.find(t) != -1) {
      cout << "Bad" << "\n";
      return;
    }
  }
  cout << "Good" << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
