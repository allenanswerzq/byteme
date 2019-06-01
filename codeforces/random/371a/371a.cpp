//============================================================================
// Name        : 371a
// Date        : Fri May 31 15:38:00 CST 2019
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
  vi a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int ret = 0;
  for (int i = 0; i < k; ++i) {
    vi cnt(3);
    for (int j = i; j < n; j += k) {
      cnt[a[j]]++;
    }
    ret += min(cnt[1], cnt[2]);
  }
  cout << ret << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
