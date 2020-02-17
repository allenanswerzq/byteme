/* created   : 2020-02-17 11:04:06
 * accepted  : 2020-02-17 11:37:15
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n; cin >> n;
  unordered_map<int, int> fr;
  unordered_map<int, int> bk;
  for (int i = 0; i < n; i++) {
    int x, y; cin >> x >> y;
    fr[x] = y;
    bk[y] = x;
  }
  int start = -1;
  for (auto it : fr) {
    if (!bk.count(it.x)) {
      start = it.x;
      break;
    }
  }
  assert(start != -1);
  int end = -1;
  for (auto it : bk) {
    if (!fr.count(it.x)) {
      end = it.x;
      break;
    }
  }
  assert(end != -1);
  if (!fr.count(start)) {
    swap(start, end);
  }
  trace(start, end);
  vector<int> ans(n, -1);
  ans[0] = start;
  ans[1] = fr[0];
  for (int i = 2; i < n; i++) {
    ans[i] = fr[ans[i - 2]];
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << (i == n - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
