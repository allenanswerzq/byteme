/* created   : 2020-03-30 20:29:47
 * accepted  : 2020-03-30 21:00:32
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

vector<string> split(string& s) {
  vector<string> ret;
  int n = s.size();
  int lo = 0;
  for (int i = 0; i <= n; i++) {
    if (s[i] == ':' || i == n) {
      ret.push_back(s.substr(lo, i - lo));
      lo = i + 1;
    }
  }
  // trace(s, ret);
  return ret;
}

void solve() {
  int n; cin >> n;
  vector<vector<string>> a;
  for (int i = 0; i < n; i++) {
    string x; cin >> x;
    // trace(x);
    a.push_back(split(x));
  }
  trace(a);
  for (auto v : a) {
    int cnt = 0;
    for (int j = 0; j < v.size(); j++) {
      if (!v[j].empty()) {
        cnt++;
      }
    }
    cnt = 8 - cnt;
    trace(v, cnt);
    string ans;
    bool ok = false;
    for (int j = 0; j < v.size(); j++) {
      if (v[j].empty()) {
        if (ok) continue;
        ok = true;
        for (int k = 0; k < cnt; k++) {
          ans += string(4, '0');
          ans += ":";
        }
      }
      else {
        if (v[j].size() != 4) {
          ans += string(4 - v[j].size(), '0');
          ans += v[j];
        }
        else {
          ans += v[j];
        }
        ans += ":";
      }
    }
    assert(!ans.empty());
    trace(ans.size());
    // assert(ans.size() == 8 * 4 + 8);
    ans.pop_back();
    cout << ans << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
