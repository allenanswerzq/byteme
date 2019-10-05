//=============================================================
// Name        : 879b
// Date        : Sat Jun  8 10:18:28 CST 2019
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
  ll n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> cnt(n + 1);
  deque<int> dq(a.begin(), a.end());
  for (int i = 0; i < n - 1; ++i) {
    if (dq[0] > dq[1]) {
      swap(dq[0], dq[1]);
    }
    cnt[dq[1]]++;
    if (cnt[dq[1]] >= k) {
      cout << dq[1]<< "\n";
      return;
    }
    dq.push_back(dq[0]);
    dq.pop_front();
  }
  cout << *max_element(a.begin(), a.end()) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
