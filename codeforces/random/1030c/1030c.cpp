//=============================================================
// Name        : 1030c
// Date        : Sat Jun  8 16:15:16 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//=============================================================
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
  int n;
  cin >> n;
  string a;
  cin >> a;
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += a[i] - '0';
  }
  trace(sum);
  if (sum == 0) {
    cout << "YES" << "\n";
    return;
  }
  for (int i = 2; i <= sum; ++i) {
    if (sum % i == 0) {
      bool ok = 1;
      int tmp = 0;
      for (int j = 0; j < n; ++j) {
        tmp += a[j] - '0';
        if (tmp == sum / i) {
          tmp = 0;
        } else if (tmp > sum / i) {
          ok = 0;
          break;
        }
      }
      if (ok) {
        trace(sum, i);
        cout << "YES" << "\n";
        return;
      }
    }
  }
  cout << "NO" << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
