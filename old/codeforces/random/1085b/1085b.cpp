//============================================================================
// Name        : 1085b
// Date        : Sun Apr 21 19:07:41 CST 2019
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

#ifndef _has_trace
#define trace(...)
#define dbstream ostream
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;

void solve() {
  int n, k;
  cin >> n >> k;
  int ret = (1 << 30);
  for (int i = 1; i <= n; ++i) {
    if (n % i == 0) {
      int x = i, b = n / i;
      int y = k * x + b;
      if (y % k == b) {
        ret = min(ret, y);
      }
    }
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
