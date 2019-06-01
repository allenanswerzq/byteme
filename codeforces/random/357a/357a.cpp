//============================================================================
// Name        : 357a
// Date        : Tue May 21 21:08:12 CST 2019
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
  int m;
  cin >> m;
  vi a(m);
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
  }
  int x, y;
  cin >> x >> y;
  int tot = accumulate(all(a), 0);
  for (int k = 1; k <= m; ++k) {
    int cnt = 0;
    for (int i = 0; i < m; ++i) {
      if (i + 1 < k) {
        cnt += a[i];
      }
    }
    trace(k, cnt, tot, x, y);
    if (x <= cnt && cnt <= y && x <= tot - cnt && tot - cnt <= y) {
      output(k);
      return;
    }
  }
  output(0);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
