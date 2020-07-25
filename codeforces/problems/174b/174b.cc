/* created   : 2020-04-04 10:57:01
 * accepted  : 2020-04-04 15:48:37
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  string s; cin >> s;
  vector<int> v;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '.') {
      v.push_back(i);
    }
  }
  if (v.empty() || v.front() > 8 || s[0] == '.' || s.back() == '.' ||
      s.size() - v.back() - 1 > 3) {
    cout << "NO" << '\n';
    return;
  }
  for (int i = 0; i + 1 < v.size(); i++) {
    if (v[i + 1] - v[i] - 1 > 11 || v[i + 1] - v[i] - 1 < 2) {
      cout << "NO" << '\n';
      return;
    }
  }
  trace(v);
  vector<string> ans;
  int lo = 0;
  for (int i = 0; i + 1 < v.size(); i++) {
    if (v[i + 1] - v[i] - 1 > 3) {
      trace(lo);
      assert(lo < s.size());
      ans.push_back(s.substr(lo, v[i] + 3 - lo + 1));
      lo = v[i] + 4;
    }
    else {
      assert(lo < s.size());
      ans.push_back(s.substr(lo, v[i] + 1 - lo + 1));
      lo = v[i] + 2;
    }
  }
  assert(lo < s.size());
  if (lo < s.size()) {
    ans.push_back(s.substr(lo));
  }
  cout << "YES" << '\n';
  for (auto t : ans) {
    cout << t << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
