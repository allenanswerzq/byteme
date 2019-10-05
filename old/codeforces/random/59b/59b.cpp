//=============================================================
// Name        : 59b
// Date        : Sun Jun  2 17:27:39 CST 2019
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
typedef vector<int> vi;

void solve() {
  int n;
  cin >> n;
  vi a, e;
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    sum += x;
    if (x % 2 == 0) {
      e.push_back(x);
    } else {
      a.push_back(x);
    }
  }
  int ret = 0;
  if (sum % 2 == 1) {
    ret = sum;
  } else {
    if (sz(a) >= 1) {
      ret = sum - *min_element(a.begin(), a.end());
    }
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
