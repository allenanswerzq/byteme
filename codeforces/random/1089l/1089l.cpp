//=============================================================
// Name        : 1089l
// Date        : Tue Jun  4 16:12:33 CST 2019
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
  vector<int> a(n), was(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i]--;
    was[a[i]] = 1;
  }
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  vector<int> mx(k), ix(k, -1);
  for (int i = 0; i < n; ++i) {
    if (b[i] > mx[a[i]]) {
      mx[a[i]] = b[i];
      ix[a[i]] = i;
    }
  }
  trace(a, b);
  vector<int> fe;
  for (int i = 0; i < n; ++i) {
    if (ix[a[i]] != i) {
      fe.push_back(b[i]);
    }
  }
  trace(fe);
  sort(fe.begin(), fe.end());
  ll ret = 0;
  int cnt = k - accumulate(was.begin(), was.end(), 0);
  for (int i = 0; i < cnt; ++i) {
    ret += fe[i];
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
