/* created   : 2020-04-08 23:30:53
 * accepted  : 2020-04-09 00:14:47
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  string s, t; cin >> s >> t;
  int n = s.size() - 1;
  while (s[n] == 'z') {
    s[n] = 'a';
    n--;
  }
  s[n]++;
  if (s == t) {
    cout << "No such string" << '\n';
  }
  else {
    cout << s << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
