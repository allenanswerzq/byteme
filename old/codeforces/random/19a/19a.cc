/* created   : 2019-08-22 09:46:10
 * accepted  : 2019-08-22 16:22:34
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

struct node {
  int a;
  int b;
  int c;
  string name;
  bool operator< (const node& rhs) {
    if (a > rhs.a) {
      return true;
    }
    else if (a == rhs.a) {
      if (b > rhs.b) {
        return true;
      }
      else if (b == rhs.b) {
        return c > rhs.c;
      }
      else {
        return false;
      }
    }
    else {
      return false;
    }
  }
  friend ostream& operator<<(ostream& os, node& a) {
    os << a.a << ' ' << a.b << ' ' << a.c << ' ' << a.name << '\n';
    return os;
  }
};

void solve() {
  int n; cin >> n;
  map<string, int> mp;
  vector<node> score(n);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    mp[s] = i;
    score[i].name = s;
  }
  for (int i = 0; i < n * (n - 1) / 2; i++) {
    string s, t;
    cin >> s >> t;
    int p = s.find('-');
    assert(p != -1);
    string a = s.substr(0, p);
    string b = s.substr(p + 1);
    p = t.find(':');
    int sa = stoi(t.substr(0, p));
    int sb = stoi(t.substr(p + 1));
    if (sa == sb) {
      score[mp[a]].a++;
      score[mp[b]].a++;
    }
    else if (sa > sb) {
      score[mp[a]].a += 3;
    }
    else {
      score[mp[b]].a += 3;
    }
    score[mp[a]].b += sa - sb;
    score[mp[b]].b += sb - sa;
    score[mp[a]].c += sa;
    score[mp[b]].c += sb;
  }
  sort(score.begin(), score.end());
  trace(score);
  vector<string> ans;
  for (int i = 0; i < n / 2; i++) {
    ans.push_back(score[i].name);
  }
  sort(ans.begin(), ans.end());
  for (int i = 0; i < (int) ans.size(); i++) {
    cout << ans[i] << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
