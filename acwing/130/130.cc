/* created   : 2020-06-02 22:07:21
 * accepted  : 2020-06-02 22:37:39
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int n; cin >> n;
  int ps = 0;
  vector<int> lt, rt;
  vector<int> mx;
  for (int i = 0; i < n; i++) {
    char op; cin >> op;
    if (op == 'I') {
      int x; cin >> x;
      ps += x;
      lt.push_back(x);
      int cur = mx.empty() ? ps : max(ps, mx.back());
      mx.push_back(cur);
    }
    else if (op == 'D') {
      if (lt.empty()) continue;
      ps -= lt.back();
      lt.pop_back();
      mx.pop_back();
    }
    else if (op == 'L') {
      if (lt.empty()) continue;
      int x = lt.back();
      ps -= x;
      lt.pop_back();
      mx.pop_back();
      rt.push_back(x);
    }
    else if (op == 'R') {
      if (rt.empty()) continue;
      int x = rt.back();
      ps += x;
      rt.pop_back();
      lt.push_back(x);
      int cur = mx.empty() ? ps : max(ps, mx.back());
      mx.push_back(cur);
    }
    else {
      int k; cin >> k;
      assert(1 <= k && k - 1 < (int) mx.size());
      cout << mx[k - 1] << "\n";
    }
    trace(ps, lt, rt, mx);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
