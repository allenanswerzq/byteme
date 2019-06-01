//============================================================================
// Name        : 257a
// Date        : Tue May 28 19:11:10 CST 2019
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
template<class T> void output(T t) { cout << t << "\n"; }
template<class T, class U, class... G>
void output(T t, U u, G... g) { cout << t << " "; output(u, g...); }

#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vi a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(rall(a));
  int ret = -1;
  if (m <= k) {
    ret = 0;
  } else {
    for (int i = 0; i < n; ++i) {
      k = k - 1 + a[i];
      if (m <= k) {
        output(i + 1);
        return;
      }
    }
  }
  output(ret);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
