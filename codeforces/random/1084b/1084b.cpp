//============================================================================
// Name        : 1084b
// Date        : Tue May 21 19:37:54 CST 2019
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
template<typename T, typename U, typename... G>
void output(T t, U u, G... g) { cout << t << " "; output(u, g...); }

#ifndef _has_trace
#define trace(...)
#define dbstream ostream
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;

void solve() {
  ll n, s;
  cin >> n >> s;
  vl a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  auto check = [&](int mid) {
    ll ret = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] < mid) {
        return false;
      } else {
        ret += a[i] - mid;
      }
    }
    return ret >= s;
  };
  ll lo = -1, hi = *max_element(all(a)) + 1;
  while (hi - lo > 1) {
    ll mid = lo + (hi - lo) / 2;
    if (check(mid)) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  output(lo);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
