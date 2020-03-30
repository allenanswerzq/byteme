/* created   : 2020-03-28 23:35:34
 * accepted  : 2020-03-29 00:35:58
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
#define xuyixuyi()
#endif
typedef long long ll;
typedef pair<int, string> pis;

bool cmp(const pis& a, const pis& b) {
  if (a.x == b.x) {
    return a.y < b.y;
  }
  else {
    return a.x > b.x;
  }
}

vector<string> split(string& s) {
  vector<string> ret;
  int lo = 0;
  int n = s.size();
  for (int i = 0; i <= n; i++) {
    if (s[i] == ' ' || i == n) {
      ret.push_back(s.substr(lo, i - lo));
      lo = i + 1;
    }
  }
  return ret;
}

void solve() {
  string a; cin >> a;
  int n; cin >> n;
  unordered_map<string, int> mp;
  string s;
  getline(cin, s);
  while (getline(cin, s)) {
    vector<string> t = split(s);
    trace(s, t);
    if (t[1] == "posted") {
      int m = t[3].size();
      assert(m >= 2);
      string x = t[3].substr(0, m - 2);
      if (t[0] == a && x != a) {
        mp[x] += 15;
      }
      else if (x == a && t[0] != a) {
        mp[t[0]] += 15;
      }
      else if (x != a && t[0] != a) {
        if (!mp.count(x)) mp[x] = 0;
        if (!mp.count(t[0])) mp[t[0]] = 0;
      }
    }
    else if (t[1] == "commented") {
      int m = t[3].size();
      assert(m >= 2);
      string x = t[3].substr(0, m - 2);
      if (t[0] == a && x != a) {
        mp[x] += 10;
      }
      else if (x == a && t[0] != a) {
        mp[t[0]] += 10;
      }
      else if (x != a && t[0] != a) {
        if (!mp.count(x)) mp[x] = 0;
        if (!mp.count(t[0])) mp[t[0]] = 0;
      }
    }
    else if (t[1] == "likes") {
      int m = t[2].size();
      assert(m >= 2);
      string x = t[2].substr(0, m - 2);
      if (t[0] == a && x != a) {
        mp[x] += 5;
      }
      else if (t[0] != a && x == a) {
        mp[t[0]] += 5;
      }
      else if (x != a && t[0] != a) {
        if (!mp.count(x)) mp[x] = 0;
        if (!mp.count(t[0])) mp[t[0]] = 0;
      }
    }
    else {
      assert(false);
    }
  }
  vector<pair<int, string>> v;
  for (auto it : mp) {
    v.push_back({it.y, it.x});
  }
  sort(all(v), cmp);
  trace(v);
  for (int i = 0; i < v.size(); i++) {
    cout << v[i].y << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
