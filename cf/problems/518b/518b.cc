/* created   : 2020-02-07 10:15:03
 * accepted  : 2020-02-07 10:29:05
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

void solve() {
  string s, t; cin >> s >> t;
  map<char, int> cnt;
  for (int i = 0; i < s.size(); i++) {
    cnt[s[i]]++;
  }
  auto decrease = [&](char ch) {
    if (--cnt[ch] == 0) {
      cnt.erase(ch);
    }
  };
  int yah = 0;
  vector<bool> use(t.size());
  for (int i = 0; i < t.size(); i++) {
    char ch = t[i];
    if (cnt[ch]) {
      use[i] = true;
      yah++;
      decrease(ch);
    }
  }
  int whoops = 0;
  for (int i = 0; i < t.size(); i++) {
    if (use[i]) { continue; }
    char ch = t[i];
    if (islower(ch) && cnt[toupper(ch)]) {
      whoops++;
      decrease(toupper(ch));
    }
    else if (isupper(ch) && cnt[tolower(ch)]) {
      whoops++;
      decrease(tolower(ch));
    }
  }
  cout << yah << ' ' << whoops << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
