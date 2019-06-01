//============================================================================
// Name        : 1082a
// Date        : Sat May 18 20:25:12 CST 2019
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
template<typename T> void output(T t) { cout << t << "\n"; }
template<typename T, typename U, typename... Args>
void output(T t, U u, Args... args) { cout << t << " "; output(u, args...); }

#ifndef _has_trace
#define trace(...)
#define dbstream ostream
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;

const int inf = 1e9 + 7;

void solve() {
  int n, x, y, d;
  cin >> n >> x >> y >> d;
  if ((y - x) % d == 0) {
    output(abs(y - x) / d);
  } else {
    int ret = inf;
    if ((y - 1) % d == 0) {
      ret = min(ret, (x - 1 + d - 1) / d + (y - 1) / d);
    }
    if ((n - y) % d == 0) {
      ret = min(ret, (n - x + d - 1) / d + (n - y) / d);
    }
    assert(ret > 0);
    output(ret == inf ? -1 : ret);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}
