/*
 * Creat   : Sat Jul 13 21:26:09 CST 2019
 * Accept  : Sat Jul 13 21:32:54 CST 2019
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
  vector<int> cnt(26);
  for (int i = 0; i < sz(s); ++i) {
    cnt[s[i] - 'a']++;
  }
  trace(cnt);
  int turn = 0;
  while (1) {
    int n = accumulate(cnt.begin(), cnt.end(), 0);
    int odd = 0;
    for (int i = 0; i < 26; ++i) {
      if (cnt[i] % 2 == 1) {
        odd++;
      }
    }
    if (n % 2 == 1 && odd == 1) {
      break;
    }
    else if (n % 2 == 0 && odd == 0) {
      break;
    }
    if (n % 2 == 1) {
      for (int i = 0; i < 26; ++i) {
        if (cnt[i] > 0 && cnt[i] % 2 == 0) {
          cnt[i]--;
          break;
        }
      }
    }
    else {
      for (int i = 0; i < 26; ++i) {
        if (cnt[i] > 0 && cnt[i] % 2 == 1) {
          cnt[i]--;
        }
      }
    }
    turn ^= 1;
  }
  cout << (!turn ? "First" : "Second") << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
