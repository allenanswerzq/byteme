/* created   : 2020-03-10 22:07:14
 * accepted  : 2020-03-11 00:08:03
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
typedef pair<char, int> pci;

const int N = 30;
int pos[N][N];

void solve() {
  int n; cin >> n;
  string s, t; cin >> s >> t;
  int cur = 0;
  for (int i = 0; i < n; i++) {
    cur += s[i] != t[i];
    if (s[i] != t[i]) {
      pos[s[i] - 'a'][t[i] - 'a'] = i + 1;
    }
  }
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      if (pos[i][j] && pos[j][i]) {
        cout << cur - 2 << '\n';
        cout << pos[i][j] << ' ' << pos[j][i] << '\n';
        return;
      }
    }
  }
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      for (int k = 0; k < 26; k++) {
        if (pos[i][j] && pos[j][k]) {
          cout << cur - 1 << '\n';
          cout << pos[i][j] << ' ' << pos[j][k] << '\n';
          return;
        }
      }
    }
  }
  cout << cur << '\n';
  cout << -1 << ' ' << -1 << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
