//=============================================================
// Name        : 143b
// Date        : Sun Jun  2 21:29:24 CST 2019
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

void solve() {
  string s;
  cin >> s;
  bool sign = 0;
  if (s[0] == '-') {
    sign = 1;
  }
  s += ".";
  // trace(s);
  string ret;
  for (int i = sign ? 1 : 0; i < sz(s); ++i) {
    if (s[i] == '.') {
      for (int j = i - 1; j >= 0; j -= 3) {
        string tmp;
        if (j - 2 < (sign ? 1 : 0)) {
          tmp = s.substr(sign ? 1 : 0, sign ? j : 1 + j);
        } else {
          tmp = s.substr(j - 2, 3);
        }
        if (sz(tmp)) {
          ret = tmp + (j == i - 1 ? "" : ",") + ret;
        }
      }
      ret += '.';
      int cnt = 0;
      for (int j = i + 1; j < sz(s) && s[j] != '.'; ++j) {
        ret += s[j], cnt++;
        if (cnt == 2) {
          break;
        }
      }
      if (cnt < 2) {
        ret += string(2 - cnt, '0');
      }
      break;
    }
  }
  ret = "$" + ret;
  if (sign) {
    ret = "(" + ret + ")";
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
