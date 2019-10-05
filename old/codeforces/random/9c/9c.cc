/* created   : 2019-09-15 16:59:31
 * accepted  : 2019-09-15 17:08:11
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

int n;
vector<int> v;

void rec(int x) {
  if (x > n) {
    return;
  }
  v.push_back(x);
  rec(x * 10);
  rec(x * 10 + 1);
}

void solve() {
  cin >> n;
  rec(1);
  trace(v);
  cout << v.size() << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
