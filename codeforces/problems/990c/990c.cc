/* created   : 2020-02-19 23:30:15
 * accepted  : 2020-02-20 00:28:58
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

pair<int, int> go(const string& s) {
  pair<int, int> ret = {-1, -1};
  // if put in the left side
  {
    // (( xxx
    bool ok = true;
    vector<char> stk;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ')') {
        if (stk.empty()) {
          ok = false;
          break;
        }
        else {
          stk.pop_back();
        }
      }
      else {
        stk.push_back('(');
      }
    }
    if (ok) {
      ret.x = stk.size();
    }
  }
  // if put in the right side
  {
    // xxx ())))
    // xxx ((((
    int left = 0;
    vector<char> stk;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ')') {
        if (stk.empty()) {
          left++;
        }
        else {
          stk.pop_back();
        }
      }
      else {
        stk.push_back('(');
      }
    }
    if (stk.empty()) {
      ret.y = left;
    }
  }
  return ret;
}

void solve() {
  int n; cin >> n;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  unordered_map<int, int> left;
  unordered_map<int, int> right;
  ll ans = 0;
  ll zero = 0;
  for (int i = 0; i < n; i++) {
    pair<int, int> r = go(a[i]);
    if (r.x > 0) {
      left[r.x]++;
    }
    if (r.y > 0) {
      right[r.y]++;
    }
    if (r.x > 0 && r.x == r.y) {
      ans++;
    }
    if (r.x == 0 && r.y == 0) {
      zero++;
    }
    trace(r, a[i]);
  }
  trace(left, right);
  for (auto it : left) {
    ans += left[it.x] * 1ll * right[it.x];
  }
  // n - 1 + n - 1
  ans = ans + zero * (zero - 1) + zero;
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
