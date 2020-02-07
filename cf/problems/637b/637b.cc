/* created   : 2020-02-06 10:41:05
 * accepted  : 2020-02-06 10:52:03
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
  list<string> a;
  unordered_map<string, decltype(a.begin())> use;
  for (int i = 0; i < n; i++) {
    string x; cin >> x;
    if (use.count(x)) {
      a.erase(use[x]);
    }
    a.push_front(x);
    use[x] = a.begin();
  }
  for (auto x : a) {
    cout << x << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
