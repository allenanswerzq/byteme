/* created   : 2020-03-21 19:33:52
 * accepted  : 2020-03-21 19:42:11
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
#define debugstream ostream
#endif
typedef long long ll;
typedef pair<int, int> pii;

map<string, int> a = {
  {"January", 0},
  {"February", 1},
  {"March", 2},
  {"April", 3},
  {"May", 4},
  {"June", 5},
  {"July", 6},
  {"August", 7},
  {"September", 8},
  {"October", 9},
  {"November", 10},
  {"December", 11}
};

void solve() {
  string x; cin >> x;
  int k; cin >> k;
  int cur = a[x];
  int ans = (cur + k) % 12;
  for (auto it : a) {
    if (it.y == ans) {
      trace(ans, it);
      cout << it.x << '\n';
      // return;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
