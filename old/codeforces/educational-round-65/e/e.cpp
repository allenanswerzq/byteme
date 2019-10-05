//============================================================================
// Name        : e
// Date        : Fri May 17 09:28:27 CST 2019
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

bool check(vi& a, int lo, int hi) {
  vi b;
  for (int i = 0; i < sz(a); ++i) {
    if (lo <= a[i] && a[i] <= hi) {
      // Do nothing
    } else {
      b.pb(a[i]);
    }
  }
  for (int i = 0; i < sz(b); ++i) {
    if (i + 1 < sz(b) && b[i] > b[i + 1]) {
      return 0;
    }
  }
  return 1;
}

void solve() {
  int n, x;
  cin >> n >> x;
  vi a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int ret = 0;
  for (int t = 1; t <= x; ++t) {
    int lo = t - 1, hi = x + 1;
    while (hi - lo > 1) {
      int  mid = lo + (hi - lo) / 2;
      if (check(a, t, mid)) {
        hi = mid;
      } else {
        lo = mid;
      }
    }
    trace(t, hi, ret);
    ret += (x - hi + 1);
    t = hi;
  }
  output(ret);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

