/*
 * creat   : 2019-07-18 15:15:56
 * accept  : 2019-07-18 15:30:27
 * author  : landcold7
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

pair<int, int> go(string& a) {
  vector<int> stk;
  int lf = 0;
  int rt = 0;
  for (auto c : a) {
    if (c == ')') {
      if (stk.empty()) {
        lf++;
      }
      else {
        stk.pop_back();
      }
    }
    else {
      stk.push_back(c);
    }
  }
  rt = (int) stk.size();
  return {lf, rt};
}

void solve() {
  int n;
  cin >> n;
  int zero = 0;
  map<int, int> lf, rt;
  for (int i = 0; i < n; ++i) {
    string x;
    cin >> x;
    auto p = go(x);
    if (p.x == 0 && p.y == 0) {
      zero++;
    }
    else if (p.x == 0 && p.y != 0) {
      rt[p.y]++;
    }
    else if (p.x != 0 && p.y == 0) {
      lf[p.x]++;
    }
  }
  int ans = zero / 2;
  for (auto it : lf) {
    if (rt.count(it.x)) {
      ans += min(it.y, rt[it.x]);
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
