//=============================================================
// Name        : 803b
// Date        : Sat Jun  1 11:39:49 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//=============================================================
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define sz(x) ((int)(x).size())

#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

void solve_binary_search() {
  int n;
  cin >> n;
  vi a(n);
  vi zero;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] == 0) {
      zero.pb(i);
    }
  }
  auto binary_search = [&](int ix) {
    int n = sz(zero);
    int lo = -1, hi = n;
    while (hi - lo > 1) {
      int mid = lo + (hi - lo) / 2;
      if (zero[mid] <= ix) {
        lo = mid;
      } else {
        hi = mid;
      }
    }
    const int inf = 1e9 + 7;
    int ret = inf;
    ret = min(ret, lo == -1 ? inf : abs(ix - zero[lo]));
    ret = min(ret, hi == n ? inf : abs(ix - zero[hi]));
    return ret;
  };
  vi ret(n);
  for (int i = 0; i < n; ++i) {
    ret[i] = binary_search(i);
  }
  for (int i = 0; i < n; ++i) {
    cout << ret[i] << (i == n - 1 ? '\n' : ' ');
  }
}

void solve() {
  int n;
  cin >> n;
  vi a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  const int inf = 1e9 + 7;
  vi lf(n, inf);
  vi rt(n, inf);
  int zero = -1;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 0) {
      lf[i] = 0, zero = i;
    } else {
      lf[i] = zero != - 1 ? i - zero : inf;
    }
  }
  zero = n;
  for (int i = n - 1; i >= 0; --i) {
    if (a[i] == 0) {
      rt[i] = 0, zero = i;
    } else {
      rt[i] = zero != n ? zero - i : inf;
    }
  }
  trace(a, lf, rt);
  for (int i = 0; i < n; ++i) {
    lf[i] = min(lf[i], rt[i]);
  }
  for (int i = 0; i < n; ++i) {
    cout << lf[i] << (i == n - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
