/*
 * created   : 2019-07-29 23:25:54
 * accepted  : 2019-07-30 10:08:53
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

const ll INF = 1e10;
vector<ll> a;
void gen(ll x) {
  if (x > INF) {
    return;
  }
  a.push_back(x);
  gen(x * 10 + 4);
  gen(x * 10 + 7);
}

ll go(ll x) {
  ll ret = 0;
  for (int i = 1; i < (int) a.size(); i++) {
    if (a[i] <= x) {
      ret += (a[i] - a[i - 1]) * a[i];
    }
    else {
      ret += (x - a[i - 1]) * a[i];
      break;
    }
  }
  return ret;
}

void solve() {
  gen(0);
  sort(a.begin(), a.end());
  ll l, r;
  cin >> l >> r;
  cout << go(r) - go(l - 1) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
