/* created   : 2020-03-15 16:30:59
 * accepted  : 2020-03-15 17:02:14
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  string s, p; cin >> s >> p;
  int m = p.size();
  int n = s.size();
  vector<int> pcnt(26);
  for (int i = 0; i < m; i++) {
    pcnt[p[i] - 'a']++;
  }
  vector<int> cnt(26);
  int special = 0;
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    if (i < m) {
      if (s[i] == '?') {
        special++;
      }
      else {
        cnt[s[i] - 'a']++;
      }
    }
    else {
      // trace(i, special, pcnt, cnt);
      int extra = special;
      bool ok = true;
      for (int j = 0; j < 26; j++) {
        if (pcnt[j] >= cnt[j]) {
          if (extra >= pcnt[j] - cnt[j]) {
            extra -= pcnt[j] - cnt[j];
          }
          else {
            ok = false;
            break;
          }
        }
        else {
          ok = false;
          break;
        }
      }
      // trace(i, ok, extra, pcnt, cnt);
      if (ok && extra == 0) {
        ans++;
      }
      if (i == n) continue;
      if (s[i] == '?') {
        special++;
      }
      else {
        cnt[s[i] - 'a']++;
      }
      if (s[i - m] == '?') {
        special--;
      }
      else {
        // trace(i, s[i - m], cnt[s[i - m] - 'a']);
        assert(cnt[s[i - m] - 'a'] > 0);
        cnt[s[i - m] - 'a']--;
      }
      // trace(i, ok, special, pcnt, cnt);
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
