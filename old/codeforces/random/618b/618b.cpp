//============================================================================
// Name        : 618b
// Date        : Sat May 18 22:23:09 CST 2019
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
  int n;
  cin >> n;
  vector<vi> g(n, vi(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> g[i][j];
    }
  }
  vi ret(n);
  bool flag = 0;
  for (int i = 0; i < n; ++i) {
    int mx = 0;
    for (int j = 0; j < n; ++j) {
      mx = max(mx, g[i][j]);
    }
    if (mx == n - 1 && !flag) {
      mx = n, flag = 1;
    }
    ret[i] = mx;
  }
  for (int i = 0; i < n; ++i) {
    cout << ret[i] << (i == n - 1 ? "\n" : " ");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
