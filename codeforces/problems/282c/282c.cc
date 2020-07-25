/* created   : 2020-04-18 21:51:31
 * accepted  : 2020-04-18 22:32:47
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

// 110
// 010
// 011
// 001
void solve() {
  // 0,0 ^0 |0
  // 0,1 ^1 |1
  // 1,0 ^1 |1
  // 1,1 ^0 |1
  string s, t; cin >> s >> t;
  if (s.size() != t.size()) {
    cout << "NO" << '\n';
    return;
  }
  int x = 0;
  for (int i = 0; i < (int) s.size(); i++) {
    x += s[i] == '1';
  }
  int y = 0;
  for (int i = 0; i < (int) t.size(); i++) {
    y += t[i] == '1';
  }
  cout << ((x > 0) ^ (y > 0) ? "NO" : "YES") << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
