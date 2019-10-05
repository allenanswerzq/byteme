//=============================================================
// Name        : 196a
// Date        : Sat Jun  1 10:24:16 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//=============================================================
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define sz(x) ((int)(x).size())

#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

void solve() {
  string s;
  cin >> s;
  vector<char> pr(sz(s) + 1, 'a');
  for (int i = sz(s) - 1; i >= 0; --i) {
    pr[i] = max(pr[i + 1], s[i]);
  }
  trace(pr);
  string ret;
  for (int i = 0; i < sz(s); ++i) {
    if (pr[i + 1] <= s[i]) {
      ret += s[i];
    }
  }
  cout << ret << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
