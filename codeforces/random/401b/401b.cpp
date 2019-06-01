//============================================================================
// Name        : 401b
// Date        : Fri May 31 15:51:09 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//============================================================================
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define sz(x) ((int)(x).size())

#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

void solve() {
  int n, k;
  cin >> n >> k;
  vi a(n + 1);
  for (int i = 0; i < k; ++i) {
    int op;
    cin >> op;
    if (op == 1) {
      int x, y;
      cin >> x >> y;
      a[x] = a[y] = 1;
    } else {
      int x;
      cin >> x;
      a[x] = 1;
    }
  }
  vi b;
  for (int i = 1; i < n; ++i) {
    if (!a[i]) {
      b.pb(i);
    }
  }
  trace(b);
  int mi = 0;
  for (int i = 0; i < sz(b); ) {
    if (i + 1 < sz(b) && b[i] + 1 == b[i + 1]) {
      i += 2;
    } else {
      i++;
    }
    mi++;
  }
  cout << mi << ' ' << sz(b) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
