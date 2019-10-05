/* Name        : 39h
 * Creat       : Thu Jul 11 10:52:19 CST 2019
 * Accept      : Thu Jul 11 11:08:54 CST 2019
 * Author      : landcold7
 * Description : Action speaks louder more than words
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
  int k;
  cin >> k;
  vector<vector<int>> a(k, vector<int>(k));
  for (int i = 1; i < k; ++i) {
    for (int j = 1; j < k; ++j) {
      int x = i * j;
      int y = 1;
      int ans = 0;
      while (x) {
        ans = (x % k) * y + ans;
        y *= 10;
        x /= k;
      }
      a[i][j] = ans;
      cout << a[i][j] << (j == k - 1 ? "\n" : " ");
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
