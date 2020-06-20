/* created   : 2020-06-20 09:20:10
 * accepted  : 2020-06-20 10:11:21
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int n, m; cin >> n >> m;
  vector<bool> wd(m + 1, true);
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int w = 1; w <= m; w++) {
      for (int j = 0; j < m; j += w) {
        for (int k = 0; k < w && j + k < m; k++) {
          if (a[i][k] != a[i][j + k]) {
            wd[w] = false;
            goto next_width;
          }
        }
      }
      next_width: (void)w;
    }
  }
  int width = -1;
  for (int i = 1; i <= m; i++) {
    if (wd[i]) {
      width = i;
      break;
    }
  }
  assert(width != -1);
  // Compute kmp at the column order.
  vector<int> fail(n, 0);
  int k = 0;
  for (int i = 1; i < n; i++) {
    while (k > 0 && !(a[i].substr(0, width) == a[k].substr(0, width))) {
      k = fail[k - 1];
    }
    if (a[i].substr(0, width) == a[k].substr(0, width)) {
      k++;
    }
    fail[i] = k;
  }
  int height = n - fail[n - 1];
  cout << width * height << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
