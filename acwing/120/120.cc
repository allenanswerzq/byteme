/* created   : 2020-05-30 16:50:03
 * accepted  : 2020-05-30 17:13:48
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

char a[1000][1000];

int power(int x, int y) {
  int ans = 1;
  for (int i = 0; i < y; i++) {
    ans *= x;
  }
  return ans;
}

void rec(int x, int y, int n) {
  if (n == 1) {
    a[x][y] = 'X';
    return;
  }
  int w = power(3, n - 2);
  rec(x, y, n - 1);
  rec(x, y + 2 * w, n - 1);
  rec(x + w, y + w, n - 1);
  rec(x + 2 * w, y, n - 1);
  rec(x + 2 * w, y + 2 * w, n - 1);
}

void solve() {
  int n;
  while (cin >> n && n != -1) {
    memset(a, 0, sizeof(a));
    rec(0, 0, n);
    int w = power(3, n - 1);
    trace(n, w);
    for (int i = 0; i < w; i++) {
      string x;
      for (int j = 0; j < w; j++) {
        x += (a[i][j] == 0 ? ' ' : a[i][j]);
      }
      cout << x << "\n";
    }
    cout << "-\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
