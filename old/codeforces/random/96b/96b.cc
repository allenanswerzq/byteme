/*
 * creat   : 2019-07-20 16:13:01
 * accept  : 2019-07-20 17:06:40
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

const ll N = 1e10 + 7;

vector<ll> e;
void rec(ll x, int a, int b) {
  if (x > N) {
    return;
  }
  if (a == b) {
    e.push_back(x);
  }
  rec(x * 10 + 4, a + 1, b);
  rec(x * 10 + 7, a, b + 1);
}

void solve() {
  int n;
  cin >> n;
  rec(0, 0, 0);
  sort(e.begin(), e.end());
  trace(sz(e));
  for (int i = 0; i < sz(e); ++i) {
    if (e[i] >= n) {
      cout << e[i] << "\n";
      return;
    }
  }
  assert(false);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
