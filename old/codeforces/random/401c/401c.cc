/*
 * Creat   : Sat Jul 13 16:46:06 CST 2019
 * Accept  : Sat Jul 13 18:45:05 CST 2019
 * Author  : landcold7
 */
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define sz(x) ((int)(x).size())
#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n, m;
  cin >> n >> m;
  if (m < n - 1 || m > 2 * (n + 1)) {
    cout << -1 << "\n";
    return;
  }
  int p = 1;
  int k = 0;
  while (n > 0 || m > 0) {
    if (p == 0 || (m > n && k < 2)) {
      m--;
      p = 1;
      k++;
    }
    else {
      n--;
      p = 0;
      k = 0;
    }
    cout << (char)(p + '0');
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
