//============================================================================
// Name        : 1093c
// Date        : Fri Apr 26 11:34:18 CST 2019
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
  vl b(n / 2);
  for (int i = 0; i < n / 2; ++i) {
    cin >> b[i];
  }
  trace(b);
  vl a(n);
  ll lo = 0, hi = (ll) 1e18;
  for (int i = 0; i < n / 2; ++i) {
    lo = max(lo, b[i] - hi);
    hi = b[i] - lo;
    a[i] = lo, a[n - i - 1] = hi;
  }
  trace(a);
  for (int i = 0; i < n; ++i) {
    cout << a[i] << (i == n - 1 ? "\n" : " ");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

