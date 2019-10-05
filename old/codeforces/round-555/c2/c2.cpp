//============================================================================
// Name        : c2
// Date        : Sat Apr 27 11:48:10 CST 2019
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
  }
  // trace(a);
  string ret;
  int  mx = 0;
  int lo = 0, hi = n - 1;
  auto ga = [&](int x, int y, int mx) {
    int c = 0;
    while (x <= y && a[x] > mx) {
      mx = a[x++], c++;
    }
    return c;
  };
  auto gb = [&](int x, int y, int mx) {
    int c = 0;
    while (x <= y && a[y] > mx) {
      mx = a[y--], c++;
    }
    return c;
  };
  while (lo <= hi) {
    if (a[lo] == a[hi]) {
      int c1 = ga(lo, hi, mx);
      int c2 = gb(lo, hi, mx);
      if (c1 > c2) {
        while (c1--) {
          ret.pb('L');
        }
      } else {
        while (c2--) {
          ret.pb('R');
        }
      }
      break;
    }
    if (mx < a[lo] && a[lo] < a[hi]) {
      mx = a[lo++], ret.pb('L');
    } else if (mx < a[hi] && a[hi] < a[lo]) {
      mx = a[hi--], ret.pb('R');
    } else if (mx < a[hi]) {
      mx = a[hi--], ret.pb('R');
    } else if (mx < a[lo]) {
      mx = a[lo++], ret.pb('L');
    } else {
      break;
    }
  }
  output(sz(ret));
  output(ret);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
