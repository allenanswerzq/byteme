//============================================================================
// Name        : 361b
// Date        : Wed May 29 10:14:30 CST 2019
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

int gcd(int a, int b) {
  if (a < b) {
    swap(a, b);
  }
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

void solve() {
  int n, k;
  cin >> n >> k;
  vi a(n + 1);
  int i = 2, c = k;
  for (i = 2; i <= n && c > 0; ++i) {
    a[i] = i;
    c--;
  }
  for (; i <= n; i += 2) {
    int t = (i + 1) == n + 1 ? 1 : i + 1;
    a[t] = i;
    a[i] = t;
  }
  if (a[1] == 0) {
    a[1] = 1;
  }
  trace(c, a);
  int cnt = 0;
  for (int j = 1; j <= n; ++j) {
    if (gcd(j, a[j]) > 1) {
      cnt++;
    }
  }
  if (cnt != k) {
    cout << -1 << "\n";
    return;
  }
  assert(cnt == k);
  for (int j = 1; j <= n; ++j) {
    cout << a[j] << (j == n ? "\n" : " ");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
