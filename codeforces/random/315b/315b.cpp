//============================================================================
// Name        : 315b
// Date        : Tue May 28 17:22:16 CST 2019
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
  int n, m;
  cin >> n >> m;
  vi a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  ll sum = 0;
  for (int i = 0; i < m; ++i) {
    int op;
    cin >> op;
    if (op == 1) {
      int v, x;
      cin >> v >> x;
      a[--v] = x - sum;
    } else if (op == 2) {
      int y;
      cin >> y;
      sum += y;
    } else if (op == 3) {
      int q;
      cin >> q;
      output(a[--q] + sum);
    } else {
      assert(0);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
