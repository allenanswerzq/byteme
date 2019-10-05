//=============================================================
// Name        : 1070k
// Date        : Sun Jun  2 11:46:48 CST 2019
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
  int n, k;
  cin >> n >> k;
  vi a(n);
  ll sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum % k != 0) {
    cout << "No\n";
    return;
  }
  vi ret;
  ll cnt = 0, pt = 0;
  for (int i = 0; i < n; ++i) {
    pt += a[i], cnt++;
    if (pt == sum / k) {
      ret.push_back(cnt);
      cnt = 0;
      pt = 0;
    }
  }
  if (sz(ret) == 0) {
    cout << "No\n";
    return;
  }
  cout << "Yes\n";
  for (int i = 0; i < sz(ret); ++i) {
    cout << ret[i] << (i == sz(ret) - 1 ? "\n" : " ");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
