//============================================================================
// Name        : c1
// Date        : Sat Apr 27 00:11:36 CST 2019
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
  trace(a);
  int lo = 0, hi = n - 1;
  string rs;
  int ret = 0, mx = 0;
  while (lo <= hi) {
    if (max(a[lo], a[hi]) < mx) {
      break;
    }
    bool ok = a[lo] < a[hi] ? 1 : 0;
    if (min(a[lo], a[hi]) > mx) {
      mx = ok ? a[lo++] : a[hi--];
      rs.pb(ok ? 'L' : 'R');
    } else {
      mx = ok ? a[hi--] : a[lo++];
      rs.pb(ok ? 'R' : 'L');
    }
    ret++;
  }
  output(ret);
  output(rs);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
