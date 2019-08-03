/*
 * Creat   : Sun Jul 14 10:36:48 CST 2019
 * Accept  : Sun Jul 14 11:07:52 CST 2019
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

void solve() {
  string s;
  cin >> s;
  int ns = (int) s.size();
  vector<int> cnt(26);
  int mark = 0;
  int pos = -1;
  for (int i = 0; i < ns; ++i) {
    if (s[i] != '?') {
      cnt[s[i] - 'A']++;
    }
    else {
      mark++;
    }
    if (i >= 25) {
      int x = 0;
      for (int j = 0; j < 26; ++j) {
        x += (cnt[j] == 1);
      }
      if (x + mark == 26) {
        pos = i;
        break;
      }
      if (s[i - 25] != '?') {
        cnt[s[i - 25] - 'A']--;
      }
      else {
        mark--;
      }
    }
  }
  if (pos == -1) {
    cout << -1 << "\n";
    return;
  }
  trace(pos, cnt);
  assert(pos >= 25);
  for (int i = pos; i > pos - 26; --i) {
    if (s[i] == '?') {
      for (int j = 0; j < 26; ++j) {
        if (cnt[j] == 0) {
          cnt[j] = 1;
          s[i] = (char)('A' + j);
          break;
        }
      }
    }
  }
  trace(s);
  for (int i = 0; i < ns; ++i) {
    if (s[i] == '?') {
      s[i] = 'A';
    }
  }
  cout << s << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
