//============================================================================
// Name        : 870b
// Date        : Sun May 19 21:47:23 CST 2019
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
  int n, k;
  cin >> n >> k;
  vi a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  if (k == 1) {
    output(*min_element(all(a)));
  } else if (k == 2) {
    int inf = 1e9 + 7;
    vi pr(n + 1, inf), sf(n + 1, inf);
    for (int i = 1; i <= n; ++i) {
      pr[i] = min(pr[i - 1], a[i - 1]);
    }
    for (int i = n - 1; i >= 0; --i) {
      sf[i] = min(sf[i + 1], a[i]);
    }
    int ret = -inf;
    for (int i = 0; i < n - 1; ++i) {
      ret = max(ret, pr[i + 1]);
      ret = max(ret, sf[i + 1]);
    }
    output(ret);
  } else {
    output(*max_element(all(a)));
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
