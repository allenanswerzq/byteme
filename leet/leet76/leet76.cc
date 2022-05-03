/* created   : 2020-09-17 18:59:39
 * accepted  : 2020-09-17 23:53:35
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

class Solution {
public:
  string minWindow(string S, string T) {
    vector<int> cnt(256);
    int need = 0;
    for (char c : T) cnt[c]++, need++;
    string ans;
    int mi = S.size() + 1;
    int have = 0;
    vector<int> win(256);
    for (int lo = 0, hi = 0; lo < S.size(); ) {
      while (hi < S.size() && have < need)   {
        if (win[S[hi]] < cnt[S[hi]]) have++;
        win[S[hi]]++;
        hi++;
      }
      // [lo, hi)
      // cout << lo << " " << hi << " " << have << " " << need << endl;
      if (have == need && mi > hi - lo) {
          mi = hi - lo;
          ans = S.substr(lo, mi);
      }
      if (win[S[lo]] == cnt[S[lo]]) have--;
      win[S[lo]]--;
      lo++;
    }
    return ans;
  }
};
