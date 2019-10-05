/*
 * creat   : 2019-07-17 12:37:31
 * accept  : 2019-07-17 13:31:52
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

int n;
void solve() {
start:
  vector<int> rank(n);
  vector<int> order(n);
  for (int i = 0; i < n; ++i) {
    cin >> rank[i];
    order[rank[i] - 1] = i;
  }
  trace(order);
  vector<int> h(n);
  for (int i = 0; i < n; ++i) {
    h[order[i]] = i;
  }
  auto go = [&](vector<int>& x) {
    vector<int> dp(n, 1);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (x[j] < x[i]) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
    }
    return *max_element(dp.begin(), dp.end());
  };
  string s;
  getline(cin, s);
  while (getline(cin, s)) {
    istringstream iss(s);
    int y;
    vector<int> x;
    while (iss >> y) {
      x.push_back(y);
    }
    if ((int) x.size() == 1) {
      n = x[0];
      goto start;
    }
    assert(sz(x) == n);
    vector<int> z(n);
    for (int i = 0; i < n; ++i) {
      z[x[i] - 1] = i;
    }
    for (int i = 0; i < n; ++i) {
      z[i] = h[z[i]];
    }
    trace(s, z);
    cout << go(z) << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  while (cin >> n) {
    solve();
  }
  return 0;
}
