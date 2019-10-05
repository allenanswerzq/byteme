//=============================================================
// Name        : 147a
// Date        : Sun Jul  7 09:46:00 CST 2019
// Accepted    : Sun Jul  7 10:28:13 CST 2019
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
  string s;
  getline(cin, s);
  string pun = ".,!?";
  string ans;
  for (auto x : s) {
    if (x == ' ') {
      if (!ans.empty() && ans.back() == ' ') {
      }
      else {
        ans += ' ';
      }
    }
    else if ((int)pun.find(x) != -1) {
      if (!ans.empty() && ans.back() == ' ') {
        ans.pop_back();
      }
      ans += x;
      ans += ' ';
    }
    else {
      ans += x;
    }
  }
  if (!ans.empty() && ans.back() == ' ') {
    ans.pop_back();
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
