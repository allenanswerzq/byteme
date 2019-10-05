//============================================================================
// Name        : b
// Date        : Sun May 26 14:58:35 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//============================================================================
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<class T> void output(T t) { cout << t << "\n"; }
template<class T, class U, class... G>
void output(T t, U u, G... g) { cout << t << " "; output(u, g...); }

#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;

struct Node {
  int s, e, l;
};

void solve(int tc) {
  int n;
  cin >> n;
  vector<Node> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].s >> a[i].e >> a[i].l;
  }
  sort(all(a), [](Node& a, Node& b) {
    return a.s * b.l < b.s * a.l;
  });
  const int maxt = 100 * 100 + 7;
  vector<ll> dp(maxt, 0);
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += a[i].s;
    vector<ll> np = dp;
    for (int t = a[i].s; t <= sum; ++t) {
      int s = a[i].s, e = a[i].e, l = a[i].l;
      e = max(0, e - (t - s) * l);
      dp[t] = max(dp[t], np[t - s] + e);
    }
  }
  ll ret = *max_element(all(dp));
  cout << "Case #" << tc << ": " << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    solve(i);
  }
  return 0;
}
