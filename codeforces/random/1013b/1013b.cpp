//============================================================================
// Name        : 1013b
// Date        : Tue May 21 15:55:31 CST 2019
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
  int n, x;
  cin >> n >> x;
  vi a(n), b(n);
  int maxn = 1e5 + 7;
  vi ma(maxn), mb(maxn);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    b[i] = a[i] & x;
    ma[a[i]]++;
    mb[b[i]]++;
  }
  for (int i = 0; i < n; ++i) {
    if (ma[a[i]] >= 2) {
      output(0);
      return;
    }
  }
  int ret = maxn;
  for (int i = 0; i < n; ++i) {
    if (mb[b[i]] >= 2) {
      if (ma[b[i]] > 0) {
        ret = min(ret, 1);
      } else {
        ret = min(ret, 2);
      }
    }
  }
  output(ret == maxn ? -1 : ret);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
