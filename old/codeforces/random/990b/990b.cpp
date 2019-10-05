//============================================================================
// Name        : 990b
// Date        : Fri Apr 26 19:26:05 CST 2019
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

int binary_search(vi& a, int k) {
  int lo = -1, hi = sz(a);
  while (hi - lo > 1) {
    int mid = lo + (hi - lo) / 2;
    if (a[mid] >= k) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  return hi < sz(a) && a[hi] == k ? hi : lo;
}

void solve() {
  int n, k;
  cin >> n >> k;
  vi a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(all(a));
  trace(k, a);
  ll ret = 0;
  for (int i = 0; i < n; ++i) {
    int ix = binary_search(a, a[i] + k);
    ret += ix == i || a[ix] == a[i];
  }
  output(ret);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
