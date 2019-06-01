//============================================================================
// Name        : 828a
// Date        : Sun May 19 14:55:11 CST 2019
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

void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  int ret = 0, c = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (x == 1) {
      if (a > 0) {
        a--;
      } else if (b > 0) {
        b--, c++;
      } else if (c > 0) {
        c--;
      } else {
        ret++;
      }
    } else if (x == 2) {
      if (b > 0) {
        b--;
      } else {
        ret += 2;
      }
    } else {
      assert(0);
    }
  }
  output(ret);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
