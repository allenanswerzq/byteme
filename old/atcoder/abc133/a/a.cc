/*
 * Name        : a
 * Creat       : Thu Jul 11 21:40:52 CST 2019
 * Accept      : Thu Jul 11 21:42:03 CST 2019
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
  int n, a, b;
  cin >> n >> a >> b;
  cout << min(n * a, b) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
