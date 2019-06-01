//============================================================================
// Name        : 892b
// Date        : Sun May 19 15:21:42 CST 2019
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
  vi a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i] = max(0, i - a[i]);
  }
  vi pr(n + 1, n);
  for (int i = n - 1; i >= 0; --i) {
    pr[i] = min(pr[i + 1], a[i]);
  }
  trace(a, pr);
  int ret = 0;
  for (int i = 0; i < n; ++i) {
    if (pr[i + 1] > i) {
      ret++;
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
