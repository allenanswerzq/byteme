//=============================================================
// Name        : 914b
// Date        : Mon Jun 10 15:41:20 CST 2019
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
  vector<int> a(n);
  const int maxn = 1e5 + 7;
  vector<int> cnt(maxn);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  int ans = 1;
  for (int i = 0; i < maxn; ++i) {
    if (cnt[i] % 2 == 1) {
      ans = 0;
      break;
    }
  }
  cout << (ans == 0 ? "Conan" : "Agasa") << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
