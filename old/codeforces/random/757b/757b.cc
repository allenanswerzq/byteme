/*
 * creat   : 2019-07-18 20:34:34
 * accept  : 2019-07-18 20:53:42
 * author  : landcold7
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

const int N = 1e5 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> a(N);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    a[x]++;
  }
  int ans = 1;
  for (int i = 2; i < N; ++i) {
    int tmp = 0;
    for (int j = i; j < N; j += i) {
      tmp += a[j];
    }
    ans = max(ans, tmp);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
