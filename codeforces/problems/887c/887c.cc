/* created   : 2020-03-17 23:05:53
 * accepted  : 2020-03-18 00:06:33
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

vector<vector<int>> d = {
  {1, 3, 5, 7, 9, 11, 24, 22},
  {2, 4, 6, 8, 10, 12, 23, 21},
  {13, 14, 5, 6, 17, 18, 21, 22},
  {15, 16, 7, 8, 19, 20, 23, 24},
  {3, 4, 17, 19, 10, 9, 16, 14},
  {1, 2, 18, 20, 12, 11, 15, 13}
};

bool check(vector<int>& b) {
  for (int i = 1; i <= 24; i += 4) {
    int col = b[i];
    for (int j = 0; j < 4; j++) {
      if (b[i + j] != col) {
        return false;
      }
    }
  }
  return true;
}

void solve() {
  vector<int> a(26);
  for (int i = 1; i <= 24; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < 6; i++) {
    vector<int> b = a;
    vector<int> dir = d[i];
    for (int j = 0; j <= 6; j += 2) {
      b[dir[j]] = a[dir[(j + 2) % 8]];
      b[dir[j + 1]] = a[dir[(j + 3) % 8]];
    }
    if (check(b)) {
      cout << "YES" << '\n';
      return;
    }
    b = a;
    for (int j = 7; j >= 1; j -= 2) {
      b[dir[j]] = a[dir[(j - 2 + 8) % 8]];
      b[dir[j - 1]] = a[dir[(j - 3 + 8) % 8]];
    }
    if (check(b)) {
      cout << "YES" << '\n';
      return;
    }
  }
  cout << "NO" << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
